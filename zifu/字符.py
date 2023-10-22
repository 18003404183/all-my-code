from PIL import Image


code_lab = ' 54321'
count = len(code_lab)
im = Image.open('2.png')
w,h = im.size
a = ''
im2 = im.convert('L')
#im2.show()
d = 0
for i in range(0,h):
    if d%2 == 0:
        c = 0
        for j in range(0,w):
            if c%3 == 0:

                gray = im2.getpixel((j,i))
                if code_lab[int(len(code_lab)*(gray/256))] == '0':
                    a+='   '
                else:
                    a = a+code_lab[int(len(code_lab)*(gray/256))]+'  '
        #print(gray)
            c += 1
            print(c)
        a+='\n'
    d += 1
#print(a)


fp = open(u'./1.txt','w')
fp.write(a)
fp.close()

