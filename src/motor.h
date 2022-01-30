typedef enum Direction {
  BACKWARD = 0,
  FORWARD = 1
};

class Motor {
  uint8_t pwm;
  uint8_t in1;
  uint8_t in2;

  uint8_t speed;
  bool isEngineMoving = false;
  Direction direction;

  Motor(uint8_t pwm, uint8_t IN1, uint8_t IN2);

  public:

  bool isMoving();
  void backward();
  void forward();
  void stop();

  private:
  void setDirection(Direction direction);
  void setIsMoving(bool isMoving);
};
