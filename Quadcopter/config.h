#define SAFE
//#define DEBUG

//----------ESC's config-----------------

//PWM values
#define MOTOR_ZERO_LEVEL 1100
#define MOTOR_ARM 140
#define MOTOR_MAX_LEVEL 2250

//Motor pins
#ifdef _DUE_BOARD
#define MOTOR_FR 2
#define MOTOR_FL 5
#define MOTOR_BR 4
#define MOTOR_BL 3
#elif defined _UNO_BOARD
#define MOTOR_BR 10
#define MOTOR_BL 9
#define MOTOR_FR 3
#define MOTOR_FL 11
#endif

//----------Rx config-------------------
#define RX_TIMEOUT 2200
//------Pins------
#ifdef _DUE_BOARD
/*
#define RX_PIN_THROTTLE 10
#define RX_PIN_PITCH 9
#define RX_PIN_ROLL 8
#define RX_PIN_YAW 11
//Auxillary - button and knobs
#define RX_PIN_AUX1 12
#define RX_PIN_AUX2 NULL
*/

#define RX_PIN_THROTTLE 10
#define RX_PIN_PITCH 11
#define RX_PIN_ROLL 12 //8
#define RX_PIN_YAW 9 //11
//Auxillary - button and knobs
#define RX_PIN_AUX1 8
#define RX_PIN_AUX2 13

#elif defined _UNO_BOARD
#define RX_PIN_THROTTLE 2
#define RX_PIN_PITCH 1
#define RX_PIN_ROLL 4
#define RX_PIN_YAW 0

//Auxillary - button and knobs
#define RX_PIN_AUX1 5
#define RX_PIN_AUX2 NULL
#endif

//------KEY VALUES-
#define RX_THROTTLE_MIN 1028
#define RX_THROTTLE_MAX 1864
#define THROTTLE_MAX MOTOR_MAX_LEVEL -(PITCH_MAX + ROLL_MAX+YAW_MAX)
#define THROTTLE_MIN MOTOR_ZERO_LEVEL + 150

#define RX_PITCH_MIN 1196
#define RX_PITCH_MAX 1703
#define PITCH_MIN -150
#define PITCH_MAX 150
#define PITCH_MIN_DEG -30
#define PITCH_MAX_DEG 30

#define RX_ROLL_MIN 1194
#define RX_ROLL_MAX 1703
#define ROLL_MIN -150
#define ROLL_MAX 150

#define RX_YAW_MIN 1035
#define RX_YAW_MAX 1867
#define YAW_MIN -150
#define YAW_MAX 150

#define RX_AUX1_MIN 1040
#define RX_AUX1_MAX 1866
#define AUX1_MIN -150
#define AUX1_MAX 150

#define RX_AUX2_MIN 1060
#define RX_AUX2_MAX 1875
#define AUX2_MIN -15
#define AUX2_MAX 15
