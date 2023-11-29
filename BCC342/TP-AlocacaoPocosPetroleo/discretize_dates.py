from datetime import datetime

def discretize_dates(date_list):
    date_objects = [datetime.strptime(date, '%d/%m/%Y') for date in date_list]
    min_date = min(date_objects)
    differences = [(date - min_date).days for date in date_objects]
    return differences


dates = ["30/11/2023", "28/11/2023", "24/12/2023", "02/02/2024", "29/11/2023", "25/12/2023",
         "02/03/2024", "11/01/2024"]

differences = discretize_dates(dates)
for date, difference in zip(dates, differences):
    print(f"{date}: {difference} dias")
