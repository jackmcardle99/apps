from bs4 import BeautifulSoup as bs
import requests

#this code is taking the articles from the war in ukraine page from the BBC website

url = 'https://www.bbc.co.uk/news/world-60525350'

html = requests.get(url)

soup = bs(html.text, "html.parser") #setting the document to html and html parser


article_box = soup.find_all('div', class_='gel-layout__item gs-u-pb+@m gel-1/3@m gel-1/4@xl gel-1/3@xxl nw-o-keyline nw-o-no-keyline@m')
                                    #this is finding the div that contains the articles

article_text = soup.find_all('p',class_="gs-c-promo-summary gel-long-primer gs-u-mt nw-c-promo-summary gs-u-display-none gs-u-display-block@m")
                                #this is finding the p tags that contain the article summaries

article_link = soup.find_all('href') # <----- this code isnt finished

i = 0
for titles in article_box: #looping through the DIVs with that specific class
    print(titles.text.upper()) #printing out the headlines
    print(article_text[i].text,'\n\n') #printing out the current headline's summary by index of loop
    i+=1
    


    