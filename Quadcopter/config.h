#define SAFE
//#define DEBUG

//----------ESC's config-----------------

//PWM values
#define MOTOR_ZERO_LEVEL 125
#define MOTOR_ARM 140
#define MOTOR_MAX_LEVEL 254

//Motor pins
#ifdef _DUE_BOARD
#define MOTOR_FR 10
#define MOTOR_FL 3
#define MOTOR_BR 11
#define MOTOR_BL 9
#elif defined _UNO_BOARD
#define MOTOR_FR 10
#define MOTOR_FL 3
#define MOTOR_BR 11
#define MOTOR_BL 9
#endif

//----------Rx config-------------------
#define RX_TIMEOUT 2200
//------Pins------
#ifdef _DUE_BOARD
#define RX_PIN_THROTTLE 7
#define RX_PIN_PITCH 4
#define RX_PIN_ROLL 2 
#define RX_PIN_YAW 8

//Auxillary - button and knobs
#define RX_PIN_AUX1 12
#define RX_PIN_AUX2 NULL
#elif defined _UNO_BOARD
#define RX_PIN_THROTTLE 7
#define RX_PIN_PITCH 4
#define RX_PIN_ROLL 2 
#define RX_PIN_YAW 8

//Auxillary - button and knobs
#define RX_PIN_AUX1 12
#define RX_PIN_AUX2 NULL
#endif

//------KEY VALUES-
#define RX_THROTTLE_MIN 1028
#define RX_THROTTLE_MAX 1864
#define THROTTLE_MAX MOTOR_MAX_LEVEL - (PITCH_MAX + ROLL_MAX + YAW_MAX)
#define THROTTLE_MIN MOTOR_ZERO_LEVEL + 25

#define RX_PITCH_MIN 1196
#define RX_PITCH_MAX 1703
#define PITCH_MIN -15
#define PITCH_MAX 15

#define RX_ROLL_MIN 1194
#define RX_ROLL_MAX 1703
#define ROLL_MIN -15
#define ROLL_MAX 15

#define RX_YAW_MIN 1035
#define RX_YAW_MAX 1867
#define YAW_MIN -15
#define YAW_MAX 15

#define RX_AUX1_MIN 1040
#define RX_AUX1_MAX 1866
#define AUX1_MIN -15
#define AUX1_MAX 15

#define RX_AUX2_MIN
#define RX_AUX2_MAX
#define AUX2_MIN -15
#define AUX2_MAX 15
