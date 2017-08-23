from __future__ import print_function
import smtplib
import sched, time
import random
import datetime

def send_email(username):
    with open('addresses.txt') as f:
        plain = f.readlines()
    nums = []
    for p in plain:
        nums.append(p.rstrip('\n'))

    for num in nums:
        server.sendmail(username, num, msg)

with open('Info') as f:
    pre = f.readlines()

earthquakes = []

for p in pre:
    earthquakes.append(p.rstrip('\n'))

with open('credentials.txt') as f:
    content = f.readlines()

username = content[0].rstrip('\n')
password = content[1].rstrip('\n')

server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login(username, password)

l1 = "\n" + earthquakes[0] + "\n" + earthquakes[1] + "\n" + earthquakes[2] + "\n"
l2 = "\n" + earthquakes[4] + "\n" + earthquakes[5] + "\n" + earthquakes[6] + "\n"
l3 = "\n" + earthquakes[8] + "\n" + earthquakes[9] + "\n" + earthquakes[10] + "\n"
l4 = "\n" + earthquakes[12] + "\n" + earthquakes[13] + "\n" + earthquakes[14] + "\n"
l5 = "\n" + earthquakes[16] + "\n" + earthquakes[17] + "\n" + earthquakes[18] + "\n"
l6 = "\n" + earthquakes[20] + "\n" + earthquakes[21] + "\n" + earthquakes[22] + "\n"
l7 = "\n" + earthquakes[24] + "\n" + earthquakes[25] + "\n" + earthquakes[26] + "\n"
l8 = "\n" + earthquakes[28] + "\n" + earthquakes[29] + "\n" + earthquakes[30] + "\n"
l9 = "\n" + earthquakes[32] + "\n" + earthquakes[33] + "\n" + earthquakes[34]

msg = l1 + l2 + l3 + l4 + l5 + l6 + l7 +l8 + l9
send_email(username)

print (datetime.datetime.now())
print('Sent: %s' % msg)

print("Update Sent");

server.quit()
