from lxml import etree
import pandas as pd
import wordcloud
import imageio
from matplotlib import pyplot as plt
import requests
from pyecharts.charts import Pie
import pyecharts.options as opts
import numpy as np

def getHtml(url):
    r = requests.get(url)
    r.encoding = r.apparent_encoding
    demo = r.text
    s = etree.HTML(demo)
    return s

def gettile(s):
    title = s.xpath('//a[starts-with(@href,"content_ICCV_2019/html")]/text()')
    print(len(title))
    print(title)
    #pd.DataFrame(title).to_csv('title.csv')
    titlecounts = {}
    remove_words = ['for', 'and', 'with', 'a', 'of', 'in',
                    'from', 'to', 'the', 'using', 'by', 'With', 'From', 'A']
    for i in title:
        words = i.split(' ')
        for word in words:
            if word in remove_words:
                continue
            else:
                titlecounts[word] = titlecounts.get(word, 0) + 1
    # 将字典存储到csv文件中
    pd.DataFrame(titlecounts, index=[0]).to_csv('hotword.csv')
    print(titlecounts)
    return titlecounts,title

def titleany(titlecounts):
    items = list(titlecounts.items())  # 将词频字典转换为二维数组
    items.sort(key=lambda x: x[1], reverse=True)  # 根据词频进行由高到低排序
    # 画柱状图
    fig, ax = plt.subplots()  # 创建图形
    x = []  # 定义x轴的值和y轴的值
    height = []
    for i in range(10):  # 遍历频率前十的词汇
        a, b = items[i]
        x.append(a)
        height.append(b)
    ax.bar(x, height, 0.5, edgecolor="blue", color="yellow")  # 创建柱状图
    ax.set_title('majority words')  # 设置title和labels
    ax.set_xlabel('word')
    ax.set_ylabel('count')
    plt.xticks(x, rotation=30)
    for i in range(10):  # 标出具体频数
        plt.text(i - 0.25, height[i] + 3, height[i])
    plt.savefig("titlehotword.jpg")
    plt.show()
    # 画词云图
    mk = imageio.imread("C:/Users/86131/Desktop/lh1.png")
    wordcloud1 = wordcloud.WordCloud(  # 创建词云图
        mask=mk,
        background_color="white",  # 设置背景为白色
        width=1500,  # 设置图片的宽度
        height=960,  # 设置图片的高度
        font_path='msyh.ttc',
        scale=15,
        #max_words=100
    ).fit_words(titlecounts)
    plt.imshow(wordcloud1, interpolation='bilinear')  # 绘制图片
    plt.axis("off")  # 消除坐标轴
    plt.savefig('hotwordcloud.jpg')
    plt.show()
    return x,height

def getname(s):
    name = s.xpath('//a[@href="#"]/text()')
    print(name)
    namecounts = {}
    for i in name:
        i1=i.strip()
        namecounts[i1] = namecounts.get(i1, 0) + 1
    pd.DataFrame(namecounts, index=[0]).to_csv('hotauthor.csv')
    print(namecounts)
    return namecounts

def nameany(namecounts):
    items = list(namecounts.items())  # 将词频字典转换为二维数组
    print(items)
    items.sort(key=lambda x: x[1], reverse=True)  # 根据词频进行由高到低排序
    # 画柱状图
    fig, ax = plt.subplots()  # 创建图形
    y = []  # 定义x轴的值和y轴的值
    height = []
    for i in range(10):  # 遍历频率前十的词汇
        a, b = items[i]
        y.append(a)
        height.append(b)
    ax.barh(y, height, 0.5, edgecolor="blue", color="yellow")  # 创建柱状图
    ax.set_title('majority authors')  # 设置title和labels
    ax.set_xlabel('count')
    ax.set_ylabel('author')
    plt.yticks(y, rotation=30)
    for i in range(10):  # 标出具体频数
        plt.text(height[i] +0.3, i-0.25, height[i])
    plt.savefig("namehotword.jpg")
    plt.show()

    # 画词云图
    mk = imageio.imread("C:/Users/86131/Desktop/lh3.png")
    wordcloud1 = wordcloud.WordCloud(  # 创建词云图
        mask=mk,
        background_color="white",  # 设置背景为白色

        width=1500,  # 设置图片的宽度

        height=960,  # 设置图片的高度

        font_path='msyh.ttc',
        scale=15,
        max_words=50

    ).fit_words(namecounts)

    plt.imshow(wordcloud1, interpolation='bilinear')  # 绘制图片

    plt.axis("off")  # 消除坐标轴
    plt.savefig('namecloud.jpg')
    plt.show()
    return y

def lengthcount(title):
    columns = ["30以下", "30~50", "51~70",
               "71~90", "91~110", "110以上"]
    words=[]
    for i in title:
        words.append(len(i))
    print(words)
    data = [0 for x in range(0, 6)]# 将长度分为六个区间
    for word in words:
        if int(word) < 30: data[0] += 1
        if int(word) >= 30 and int(word) < 51: data[1] += 1
        if int(word) >= 51 and int(word) < 71: data[2] += 1
        if int(word) >= 71 and int(word) < 91: data[3] += 1
        if int(word) >= 91 and int(word) < 111: data[4] += 1
        if int(word) >= 111: data[5] += 1
         # 生成饼图
    c = (Pie()
            .add(
            "",
            [list(z) for z in zip(columns, data)],
            radius=["30%", "75%"],
            center=["35%", "50%"],
            rosetype="radius",
            )
            .set_global_opts(title_opts=opts.TitleOpts(title="Statistics of title length"))
            )
    c.render("Pie.html")
    return words

def avghot(titles,word,titlelength,count):
    ave = [0 for x in range(0, 10)]# 存储每个热点词平均标题长度
    for title in titles: # 遍历所有标题
        for i in range(10): # 查找该标题是否含有热点词汇
            if word[i] in title: # 如果有
                j = titles.index(title)# 获取该标题的索引
                ave[i] += int(titlelength[j]) # 累加上该标题长度
    for i in range(10):
        ave[i] = round(ave[i] / count[i], 2) # 算平均长度，保存两位小数
    fig, ax = plt.subplots()
    ax.plot(word, ave, marker='*', ms=10)
    ax.set_title('The average title length of hot words')
    ax.set_xlabel('hot word')
    ax.set_ylabel('Average title length')
    plt.xticks(word, rotation=30)
    for i in range(10):  # 标出具体频数
        plt.text(i - 0.25, ave[i] + 2, ave[i])
    plt.savefig("avgtitlelength.jpg")
    plt.show()

def getnum(s):
    num1 = s.xpath('//div[@class="bibref"]/text()')
    num1=list(num1)
    print(num1)
    num=[]
    namenum=[]
    namenum1=[]
    namenum2=[]
    numname=[]
    for i in range(len(num1)):
        if i %7==1:
            num.append(num1[i])
    for i in num:
        l=i[11:len(i)-2]
        namenum.append(l)
    for i in namenum:
        l=i.split("and")
        namenum1.append(l)
    for i in namenum1:
        m=[]
        for j in i:
            if "," in j:
                l=j.split(",")
                l1=l[0].strip()
                l2=l[1].strip()
                sl=l2+" "+l1
                m.append(sl)
            else:
                j1=j.strip()
                m.append(j1)
        namenum2.append(m)
    for i in namenum2:
        numname.append(len(i))
    print(numname)
    #pd.DataFrame(namenum2).to_csv('name.csv')
    return numname,namenum2

def hotwordandauthor(authors,hotauthor,titles,hotword):
    hotword3author = np.zeros((4, 10)) # 定义最终结果矩阵
    for author in authors:  # 遍历所有作者
        for i in range(4):
            if hotauthor[i] in author: # 如果发现热门作者
                index = authors.index(author)# 得到该作者的位置索引
                title = titles[index] # 得到该文章的标题
                for j in range(10):
                    if hotword[j] in title:  # 若发现标题中有热门词汇
                        hotword3author[i][j] += 1  # 计数
    fig, ax = plt.subplots() # 画图
    data = hotword3author
    height=[]
    for i in range(10):
        sum=0
        for j in range(4):
            sum+=hotword3author[j][i]
        height.append(sum)
    color_list = ['b', 'g', 'r', 'y']
    mybar = []
    for i in range(4):  # 需要绘制四次柱状图
        mybar.append(ax.bar(hotword, data[i], # 一次绘制矩阵中的一行
            width = 0.35,
            bottom = np.sum(data[:i], axis=0),
            color = color_list[i],
            alpha = 0.5,
            label=hotauthor[i]

            ))
    ax.set_title('The number of hot words in hot authors')# 设置title和labels
    ax.set_xlabel('word')
    ax.set_ylabel('count')
    plt.xticks(hotword, rotation=30)
    for i in range(10):  # 标出具体频数
        plt.text(i - 0.25, height[i]+0.3 , height[i])
    plt.legend(loc="upper right")
    plt.savefig("hotwordsandauthor.jpg")
    plt.show()



def main():
    url = "http://openaccess.thecvf.com/ICCV2019.py"
    s=getHtml(url)
    titlecounts,titles=gettile(s)
    hotwords,counts=titleany(titlecounts)
    namecounts=getname(s)
    producauthor=nameany(namecounts)
    length=lengthcount(titles)
    avghot(titles,hotwords,length,counts)
    namenum,name=getnum(s)
    hotwordandauthor(name,producauthor,titles,hotwords)


main()