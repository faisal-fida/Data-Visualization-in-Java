float x;
float y;
float xSpeed;
float ySpeed;

void setup() {
    size(800, 450);
    x = random(width);
    y = random(height);
    xSpeed = random(-1,1.5);
    ySpeed = random(-1,1.5);
}

void draw() {
    background(0);
    x += xSpeed;
    y += ySpeed;

    if(x > width || x < 0) {
        xSpeed = -xSpeed;
    }
    if(y > height || y < 0) {
        ySpeed = -ySpeed;
    }
    fill(255, 255, 255);
    ellipse(x,y,15,15);
}
