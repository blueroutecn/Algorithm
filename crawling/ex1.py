import requests

r = requests.get('https://medium.com/@mjhans83/%ED%8C%8C%EC%9D%B4%EC%8D%AC%EC%9C%BC%EB%A1%9C-%ED%81%AC%EB%A1%A4%EB%A7%81-%ED%95%98%EA%B8%B0-908e78ee09e0',
auth = ('user','pass'))

r.status_code

r.headers['content-type']

r.encoding

r.text
r.json()


def get_html(url):
    headers = {'User-Agent':'Chrome/66.0.3359.181'}
    _html = ""
    resp = requests.get(url,headers = headers)
    if resp.status_code == 200:
        _html = resp.text
    return _html


from bs4 import BeautifulSoup


URL = "http://comic.naver.com/webtoon/list.nhn?titleId=20853&weekday=tue&page=1"

html = get_html(URL)

soup = BeautifulSoup(html,'html.parser')

print(soup.prettify())

ct = soup.findAll('td',attrs = {'class':'title'})
link = ct[0].find('a')['href']

html = get_html('http://toors.tistory.com/entry/Python-BeautifulSoup%EC%9C%BC%EB%A1%9C-%EA%B2%8C%EC%8B%9C%ED%8C%90-%EA%B8%81%EC%96%B4%EC%98%A4%EA%B8%B0-%ED%8C%A8%ED%84%B4')
soup = BeautifulSoup(html,'html.parser')
ct = soup.findAll('a')
ct[1].find('a')


import urllib
from bs4 import BeautifulSoup
html = get_html('http://comic.naver.com/webtoon/weekday.nhn')
soup = BeautifulSoup(html, "lxml")

titles = soup.find_all("a")

resp = requests.get('http://toors.tistory.com/entry/Python-BeautifulSoup%EC%9C%BC%EB%A1%9C-%EA%B2%8C%EC%8B%9C%ED%8C%90-%EA%B8%81%EC%96%B4%EC%98%A4%EA%B8%B0-%ED%8C%A8%ED%84%B4',headers = headers)
resp.text
