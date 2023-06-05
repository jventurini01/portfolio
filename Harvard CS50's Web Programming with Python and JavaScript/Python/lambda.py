people = [
    {"name": "joey", "league": "Masters"},
    {"name": "Salem", "league": "Expert"},
    {"name": "Violet", "league": "Intermediate"}
]
    
people.sort(key=lambda person: person["name"])
print(people)