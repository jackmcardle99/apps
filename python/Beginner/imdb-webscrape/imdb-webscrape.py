from bs4 import BeautifulSoup as bs
import requests

url = "https://www.imdb.com/chart/top/?ref_=nv_mv_250"

page = requests.get(url)
soup = bs(page.content, "html.parser")

table = soup.find("table")
head = soup.find("thead")
#thing = soup.find("th")

#print(head.text)
for thing in table:
   print(thing.text)