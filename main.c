float x, y;
float xSpeed, ySpeed;
int ballCount = 35;
int lineCount = 300;
int numCircles = 30;
float xpos[], ypos[], xspeed[], yspeed[];
ArrayList < Ball > balls;
ArrayList < Line > lines;

void setup() {
  size(800, 450);
  strokeWeight(2);
  stroke(255);
  noFill();
  x = width / 2;
  y = height / 2;
  xSpeed = 1.2;
  ySpeed = 1.2;
  xpos = new float[numCircles];
  ypos = new float[numCircles];
  xspeed1 = new float[numCircles];
  yspeed1 = new float[numCircles];

  for (int i = 0; i < numCircles; i++) {
    xpos[i] = random(width);
    ypos[i] = random(height);
    xspeed1[i] = random(-0.5, 0.5);
    yspeed1[i] = random(-0.5, 0.5);
  }

  balls = new ArrayList < Ball > ();
  lines = new ArrayList < Line > ();
  for (int i = 0; i < ballCount; i++) {
    balls.add(new Ball(random(width), random(height)));
  }
  for (int i = 0; i < lineCount; i++) {
    Ball start = balls.get(int(random(balls.size())));
    Ball end = balls.get(int(random(balls.size())));
    lines.add(new Line(start, end));
  }
}

void draw() {
  background(0);
  switch (key) {
  case 'a':
    x += xSpeed;
    y += ySpeed;
    if (x > width || x < 0) {
      xSpeed = -xSpeed;
    }
    if (y > height || y < 0) {
      ySpeed = -ySpeed;
    }
    fill(255, 255, 255);
    ellipse(x, y, 15, 15);
    break;
  case 's':
    // code for display mode 1
    for (Ball b: balls) {
      b.move();
      b.display();
    }
    strokeWeight(1.5);
    stroke(255, 255, 255);
    for (Line l: lines) {
      l.move();
      l.display();
    }
    break;
  case 'd':
    // code for display mode 2
    for (int i = 0; i < numCircles; i++) {
      ellipse(xpos[i], ypos[i], 20, 20);
      for (int j = i + 1; j < numCircles; j++) {
        float distance = dist(xpos[i], ypos[i], xpos[j], ypos[j]);
        if (distance < 120) {
          line(xpos[i], ypos[i], xpos[j], ypos[j]);
        }
      }
      xpos[i] += xspeed1[i];
      ypos[i] += yspeed1[i];
      if (xpos[i] > width || xpos[i] < 0) {
        xspeed1[i] = -xspeed1[i];
      }
      if (ypos[i] > height || ypos[i] < 0) {
        yspeed[i] = -yspeed[i];
      }
    }
    break;
  }
}

class Ball {
  float x, y, xSpeed, ySpeed;

  Ball(float x, float y) {
    this.x = x;
    this.y = y;
    xSpeed = 0.001;
    ySpeed = 0.001;
  }

  void move() {
    x += xSpeed;
    y += ySpeed;
  }

  void display() {
    fill(255, 255, 255);
    ellipse(x, y, 20, 20);
  }
}

class Line {
  Ball start, end;
  float xSpeed, ySpeed;

  Line(Ball start, Ball end) {
    this.start = start;
    this.end = end;
    xSpeed = (end.x - start.x) / 6000;
    ySpeed = (end.y - start.y) / 6000;
  }

  void move() {
    start.x += xSpeed;
    start.y += ySpeed;
    end.x += xSpeed;
    end.y += ySpeed;
  }

  void display() {
    line(start.x, start.y, end.x, end.y);
  }
}
