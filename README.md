# are-you-a-hotty-then-cool-down-your-body

---

## Inspiration
Our inspiration for this project came from our experiences attending a High School with no air conditioning. Sitting in classes after the gym or during the hotter months of the year led to lower productivity for us so in hopes of raising our productivity and having more self-development time, we decided to build a smart desktop fan.

---

## What it does
As we approach the summertime, temperatures and humidity levels are getting higher and higher, making it harder for students and educators to focus on their learning. This device allows students a convenient and easy way to cool down and stay comfortable while working. It achieves this goal by using a state-of-the-art fan to project air onto a person which will remove the heat from them through force convection (displacing the warm air around their body with cooler air), thus reducing overall body temperature. The fan speed will change based on either the ambient temperature or the user input by the remote or online user interface. The four LEDs indicate the speed of the fan (red: slowest (0%), yellow: slow (33%), green: fast (67%), blue: fastest (100%)).

![alt text](https://d112y698adiu2z.cloudfront.net/photos/production/software_photos/002/505/788/datas/gallery.jpg)
Full Picture of Fans

---

## How we built it
We were able to build this project with an Arduino running C++. We hooked up an LCD display with a potentiometer (which controls the brightness) to display the temperature and humidity based on values received by a sensor (DHT-22). An IR receiver was also used to receive signals from the IR remote for fan speed control. A DC motor was used to turn the fan.

---

## Challenges we ran into
We ran into three major problems while building this project. First, the changes in temperature weren’t reflected correctly on the LCD display. However, this problem was fixed upon the discovery that our LCD display was placed on the wrong side of the board. Secondly, LED indicators were not lighting up. This issue was fixed when their placement on the board was brought closer to the circuit. Bringing the LEDs closer to the circuit helped the LEDs receive more current. Thirdly, the fan did not spin when turned on. This problem was fixed when the motor speed was increased. The reason the fans were not spinning was due to the weight of the fan was too much for the power that the motors were set at.

---

## Accomplishments that we're proud of
On top of solving the above-mentioned problems, we were able to figure out and learn a lot because we were relatively inexperienced with Arduino and circuit equipment. Hence, it was a fun and enjoyable learning experience. We are happy to have made useful desktop hardware to benefit students in their everyday lives. We were also able to make a website that controls the fan through Node.JS.

---

## What we learned
We learned time management and working as a team. We improved our communication and collaboration skills with each other throughout this entire building and coding experience. As previously mentioned we developed circuitry and Arduino skills and are excited to explore and expand these skills in future hackathons.

---

## What's next for Hottie Cooler
In the future, we plan on adding an additional fan for twice the cooling ability and an automated scented mister for more comfort and superior cooling action.

---

## Built With
 - arduino
 - c++
 - css
 - html
 - javascript
 - node.js
 - socket.io

---

## Contributors

- Daniel Eskiocak <karad0012@wrdsb.ca>
- Jacob Bakker <jacalebak@gmail.com>
- Joshua Dierickse <joshua.dierickse@gmailcom>
- Peter Song <petersong1113@gmail.com>

---

## License & Copyright

© Daniel Eskiocak, Laurel Heights Secondary School
© Jacob Bakker, Waterloo Collegiate Institute
© Joshua Dierickse, Waterloo Collegiate Institute
© Peter Song, Laurel Heights Secondary School
