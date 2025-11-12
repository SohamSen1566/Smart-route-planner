#!/usr/bin/env python3

import pandas as pd
import requests
import time
from tqdm import tqdm
import os


BASE = os.path.dirname(os.path.dirname(__file__))
CITY_FILE = os.path.join(BASE, "data", "in.csv")
OUT_FILE = os.path.join(BASE, "data", "city_distances.csv")

TOP_N = 100
NEIGHBORS = 10    # Number of nearest cities per city
SLEEP = 1.0       # Seconds between API requests (be nice to OSRM)
OSRM_URL = "http://router.project-osrm.org/route/v1/driving/{},{};{},{}?overview=false"

print("[+] Loading city data...")
df = pd.read_csv(CITY_FILE)

# Detect correct column names
lat_col = None
lon_col = None
pop_col = None

for col in df.columns:
    c = col.strip().lower()
    if c in ["lat", "latitude"]:
        lat_col = col
    elif c in ["lng", "lon", "longitude"]:
        lon_col = col
    elif c in ["population", "pop", "population_proper"]:
        pop_col = col

if lat_col is None or lon_col is None:
    raise ValueError("Couldn't find latitude/longitude columns in in.csv")

if pop_col:
    print(f"[+] Sorting by population column: '{pop_col}'")
    df = df.sort_values(pop_col, ascending=False).head(TOP_N).reset_index(drop=True)
else:
    print("[⚠️] No population column found — using first TOP_N rows as-is.")
    df = df.head(TOP_N).reset_index(drop=True)

def get_distance(lat1, lon1, lat2, lon2):
    """Get road distance (in km) between two coordinates using OSRM."""
    url = OSRM_URL.format(lon1, lat1, lon2, lat2)
    try:
        r = requests.get(url, timeout=10)
        data = r.json()
        if "routes" in data and len(data["routes"]) > 0:
            return round(data["routes"][0]["distance"] / 1000, 2)
    except Exception as e:
        print(f"[Error] {e}")
    return None

rows = []
print(f"[+] Generating routes for top {TOP_N} cities...")

for i, city in tqdm(df.iterrows(), total=len(df)):
    city_name = city["city"]
    lat1, lon1 = city[lat_col], city[lon_col]

    # find nearest neighbors by straight-line distance
    df["temp"] = ((df[lat_col] - lat1) ** 2 + (df[lon_col] - lon1) ** 2) ** 0.5
    nearest = df.nsmallest(NEIGHBORS + 1, "temp").iloc[1:]  # skip self

    for _, ncity in nearest.iterrows():
        city2 = ncity["city"]
        lat2, lon2 = ncity[lat_col], ncity[lon_col]

        dist = get_distance(lat1, lon1, lat2, lon2)
        if dist:
            # Add both directions
            rows.append((city_name, city2, dist))
            rows.append((city2, city_name, dist))
        time.sleep(SLEEP)


os.makedirs(os.path.join(BASE, "data"), exist_ok=True)
out_df = pd.DataFrame(rows, columns=["Origin", "Destination", "Distance_km"])
out_df.to_csv(OUT_FILE, index=False)

print(f"\n Done! File saved to: {OUT_FILE}")
print(f" Total routes generated: {len(out_df)}")
print("Tip: Increase TOP_N to 1000 for a full-scale dataset.")
