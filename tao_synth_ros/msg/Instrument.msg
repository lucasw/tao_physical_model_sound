# TODO(lucasw) eventually want arbitrary geometry,
# but use the built-in types for now.
uint8 STRAND=0
uint8 RECTANGLE=1
uint8 TRIANGLE=2
uint8 CIRCLE=3
uint8 ELLIPSE=4
uint8 ADD=0
uint8 REMOVE=1
string name  # must be unique
string text
# currently only strand supported
int32 type
int32 action
# TODO(lucasw) is a header needed?
std_msgs/Header header
geometry_msgs/Point position
float32 pitch_x
float32 pitch_y
float32 decay
