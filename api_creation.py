from fastapi import FASTAPI
app = FASTAPI()
@app.get("/")
def home():
    return {"message": "Smart Delivery Route Planner is running!"}