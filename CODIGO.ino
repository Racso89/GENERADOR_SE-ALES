#include <SoftwareSerial.h>
int boton= 10;
int contador=0;
int estadoback=0;
int lectura=0;
SoftwareSerial transmision(8,9); //RX||TX
const PROGMEM  int SENOIDAL[500] ={127,129,130,132,133,135,137,138,140,141,143,145,146,148,149,151,152,154,156,157,159,160,162,163,165,166,168,169,171,172,174,175,177,178,180,181,183,184,185,187,188,190,191,192,194,195,197,198,199,200,202,203,204,206,207,208,209,211,212,213,214,215,216,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,234,235,236,237,238,238,239,240,241,241,242,243,243,244,245,245,246,246,247,247,248,248,249,249,250,250,250,251,251,252,252,252,252,253,253,253,253,253,254,254,254,254,254,254,254,254,254,254,254,254,254,254,253,253,253,253,253,252,252,252,252,251,251,251,250,250,249,249,249,248,248,247,247,246,245,245,244,244,243,242,242,241,240,240,239,238,237,236,236,235,234,233,232,231,230,229,228,227,227,226,224,223,222,221,220,219,218,217,216,215,213,212,211,210,209,207,206,205,204,202,201,200,199,197,196,194,193,192,190,189,188,186,185,183,182,180,179,178,176,175,173,172,170,169,167,166,164,163,161,159,158,156,155,153,152,150,148,147,145,144,142,141,139,137,136,134,133,131,129,128,126,125,123,121,120,118,117,115,113,112,110,109,107,106,104,102,101,99,98,96,95,93,91,90,88,87,85,84,82,81,79,78,76,75,74,72,71,69,68,66,65,64,62,61,60,58,57,55,54,53,52,50,49,48,47,45,44,43,42,41,39,38,37,36,35,34,33,32,31,30,28,27,27,26,25,24,23,22,21,20,19,18,18,17,16,15,14,14,13,12,12,11,10,10,9,9,8,7,7,6,6,5,5,5,4,4,3,3,3,2,2,2,2,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,2,2,2,2,3,3,4,4,4,5,5,6,6,7,7,8,8,9,9,10,11,11,12,13,13,14,15,16,16,17,18,19,20,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,38,39,40,41,42,43,45,46,47,48,50,51,52,54,55,56,57,59,60,62,63,64,66,67,69,70,71,73,74,76,77,79,80,82,83,85,86,88,89,91,92,94,95,97,98,100,102,103,105,106,108,109,111,113,114,116,117,119,121,122,124,125,127};
const PROGMEM byte EXPOCRE[500] ={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10,10,10,10,11,11,11,11,11,11,11,11,12,12,12,12,12,12,12,12,13,13,13,13,13,13,13,14,14,14,14,14,14,15,15,15,15,15,15,16,16,16,16,16,16,17,17,17,17,17,18,18,18,18,18,19,19,19,19,19,20,20,20,20,20,21,21,21,21,22,22,22,22,23,23,23,23,24,24,24,24,25,25,25,26,26,26,26,27,27,27,28,28,28,29,29,29,29,30,30,30,31,31,31,32,32,33,33,33,34,34,34,35,35,36,36,36,37,37,38,38,38,39,39,40,40,41,41,41,42,42,43,43,44,44,45,45,46,46,47,47,48,48,49,49,50,51,51,52,52,53,53,54,55,55,56,56,57,58,58,59,60,60,61,62,62,63,64,64,65,66,67,67,68,69,70,70,71,72,73,74,74,75,76,77,78,79,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,104,105,106,107,108,109,111,112,113,114,116,117,118,120,121,122,124,125,126,128,129,131,132,133,135,136,138,139,141,143,144,146,147,149,151,152,154,156,157,159,161,163,165,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,201,203,205,207,210,212,214,217,219,222,224,227,229,232,234,237,239,242,245};
const PROGMEM byte AMORTEX[500] ={107,124,140,156,171,185,198,209,220,229,237,243,248,251,253,253,252,249,245,240,233,226,217,207,197,186,174,162,149,137,124,111,99,87,75,64,54,44,35,27,20,14,9,5,3,1,0,1,2,5,9,13,18,24,31,39,47,55,64,73,82,91,101,110,119,127,135,143,151,157,163,169,173,177,180,183,184,185,185,184,182,180,177,173,169,164,159,153,147,141,134,128,121,114,107,101,94,88,83,77,72,67,63,60,57,54,52,51,50,50,51,52,53,55,58,61,64,68,72,76,81,85,90,95,100,105,110,115,119,123,128,131,135,138,141,143,145,147,148,148,149,148,148,147,145,144,142,139,137,134,131,127,124,121,117,113,110,106,103,99,96,93,90,88,85,83,81,80,78,78,77,77,77,77,78,79,80,81,83,85,87,89,91,94,96,99,101,104,107,109,112,114,116,119,121,122,124,125,127,128,128,129,129,129,129,129,128,127,126,125,124,122,121,119,117,116,114,112,110,108,106,104,102,101,99,98,96,95,94,93,92,92,91,91,91,91,91,91,92,93,93,94,95,96,98,99,100,102,103,104,106,107,109,110,111,112,113,115,115,116,117,118,118,118,119,119,119,119,118,118,118,117,116,116,115,114,113,112,111,110,109,108,107,106,105,104,103,103,102,101,100,100,99,99,99,99,98,98,98,99,99,99,99,100,100,101,102,102,103,104,104,105,106,107,107,108,109,109,110,111,111,112,112,112,113,113,113,113,113,113,113,113,113,113,112,112,112,111,111,110,110,109,109,108,107,107,106,106,105,105,104,104,104,103,103,103,103,103,102,102,102,102,103,103,103,103,103,104,104,104,105,105,105,106,106,107,107,107,108,108,108,109,109,109,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,109,109,109,109,108,108,108,107,107,107,107,106,106,106,106,105,105,105,105,105,105,105,105,105,105,105,105,105,105,105,105,105,105,106,106,106,106,106,107,107,107,107,107,108,108,108,108,108,108,109,109,109,109,109,109,109,109,109,109,109,109,108,108,108,108,108,108,108,108,107,107,107,107,107,107,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,107,107};
const PROGMEM byte CUADRADA[500] ={253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,253,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,253};
const PROGMEM byte TRIANGULO[500] ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,250,249,248,247,246,245,244,243,242,241,240,239,238,237,236,235,234,233,232,231,230,229,228,227,226,225,224,223,222,221,220,219,218,217,216,215,214,213,212,211,210,209,208,207,206,205,204,203,202,201,200,199,198,197,196,195,194,193,192,191,190,189,188,187,186,185,184,183,182,181,180,179,178,177,176,175,174,173,172,171,170,169,168,167,166,165,164,163,162,161,160,159,158,157,156,155,154,153,152,151,150,149,148,147,146,145,144,143,142,141,140,139,138,137,136,135,134,133,132,131,130,129,128,127,126,125,124,123,122,121,120,119,118,117,116,115,114,113,112,111,110,109,108,107,106,105,104,103,102,101,100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
const PROGMEM byte SIERRA[500] ={1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15,16,16,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,25,25,26,26,27,27,28,28,29,30,30,31,31,32,32,33,33,34,34,35,35,36,36,37,37,38,38,39,39,40,40,41,41,42,42,43,43,44,44,45,45,46,46,47,47,48,48,49,49,50,50,51,51,52,52,53,53,54,54,55,55,56,56,57,58,58,59,59,60,60,61,61,62,62,63,63,64,64,65,65,66,66,67,67,68,68,69,69,70,70,71,71,72,72,73,73,74,74,75,75,76,76,77,77,78,78,79,79,80,80,81,81,82,82,83,83,84,84,85,85,86,87,87,88,88,89,89,90,90,91,91,92,92,93,93,94,94,95,95,96,96,97,97,98,98,99,99,100,100,101,101,102,102,103,103,104,104,105,105,106,106,107,107,108,108,109,109,110,110,111,111,112,112,113,113,114,115,115,116,116,117,117,118,118,119,119,120,120,121,121,122,122,123,123,124,124,125,125,126,126,127,127,128,128,129,129,130,130,131,131,132,132,133,133,134,134,135,135,136,136,137,137,138,138,139,139,140,140,141,141,142,143,143,144,144,145,145,146,146,147,147,148,148,149,149,150,150,151,151,152,152,153,153,154,154,155,155,156,156,157,157,158,158,159,159,160,160,161,161,162,162,163,163,164,164,165,165,166,166,167,167,168,168,169,169,170,171,171,172,172,173,173,174,174,175,175,176,176,177,177,178,178,179,179,180,180,181,181,182,182,183,183,184,184,185,185,186,186,187,187,188,188,189,189,190,190,191,191,192,192,193,193,194,194,195,195,196,196,197,197,198,198,199,200,200,201,201,202,202,203,203,204,204,205,205,206,206,207,207,208,208,209,209,210,210,211,211,212,212,213,213,214,214,215,215,216,216,217,217,218,218,219,219,220,220,221,221,222,222,223,223,224,224,225,225,226,226,227,228,228,229,229,230,230,231,231,232,232,233,233,234,234,235,235,236,236,237,237,238,238,239,239,240,240,241,241,242,242,243,243,244,244,245,245,246,246,247,247,248,248,249,249,250,250,251,251,252,252,253,253,254,254,1};
const PROGMEM byte SINC[500] ={46,47,48,49,49,50,51,52,53,53,54,55,55,56,57,57,58,58,59,59,60,60,60,60,61,61,61,61,61,60,60,60,60,59,59,58,58,57,57,56,55,54,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,31,30,30,29,29,28,28,27,27,27,27,27,27,27,28,28,28,29,29,30,31,31,32,33,34,35,36,37,38,40,41,42,44,45,46,48,49,50,52,53,55,56,57,59,60,61,63,64,65,66,67,68,69,70,70,71,71,72,72,72,73,73,72,72,72,72,71,71,70,69,68,67,66,65,63,62,60,59,57,55,53,51,49,47,45,43,41,39,37,35,32,30,28,26,24,22,20,18,16,14,12,11,9,8,6,5,4,3,2,2,1,1,1,1,1,2,2,3,4,5,7,9,10,12,15,17,20,23,26,29,32,36,40,44,48,52,56,61,66,71,76,81,86,91,97,102,108,113,119,125,130,136,142,147,153,158,164,169,175,180,185,190,195,200,205,209,214,218,222,225,229,232,235,238,241,243,245,247,249,250,251,252,253,253,253,253,252,251,250,249,247,245,243,241,238,235,232,229,225,222,218,214,209,205,200,195,190,185,180,175,169,164,158,153,147,142,136,130,125,119,113,108,102,97,91,86,81,76,71,66,61,56,52,48,44,40,36,32,29,26,23,20,17,15,12,10,9,7,5,4,3,2,2,1,1,1,1,1,2,2,3,4,5,6,8,9,11,12,14,16,18,20,22,24,26,28,30,32,35,37,39,41,43,45,47,49,51,53,55,57,59,60,62,63,65,66,67,68,69,70,71,71,72,72,72,72,73,73,72,72,72,71,71,70,70,69,68,67,66,65,64,63,61,60,59,57,56,55,53,52,50,49,48,46,45,44,42,41,40,38,37,36,35,34,33,32,31,31,30,29,29,28,28,28,27,27,27,27,27,27,27,28,28,29,29,30,30,31,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,54,55,56,57,57,58,58,59,59,60,60,60,60,61,61,61,61,61,60,60,60,60,59,59,58,58,57,57,56,55,55,54,53,53,52,51,50,49,49,48,47,46};
const PROGMEM byte PARTICULAR1[500] ={84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,0,2,3,4,6,7,8,10,11,12,14,15,16,18,19,21,22,23,25,26,27,29,30,31,33,34,35,37,38,39,41,42,43,45,46,47,49,50,52,53,54,56,57,58,60,61,62,64,65,66,68,69,70,72,73,74,76,77,78,80,81,82,84,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,168,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,168,166,165,164,162,161,160,158,157,156,154,153,152,150,149,148,146,145,144,142,141,140,138,137,136,134,133,131,130,129,127,126,125,123,122,121,119,118,117,115,114,113,111,110,109,107,106,105,103,102,100,99,98,96,95,94,92,91,90,88,87,86,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84,84};
const PROGMEM byte PARTICULAR2[500] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,251,249,247,245,243,241,239,237,235,233,231,229,227,225,223,221,219,217,215,213,211,209,207,205,203,201,198,196,194,192,190,188,186,184,182,180,178,176,174,172,170,168,166,164,162,160,158,156,154,152,150,148,146,144,142,140,138,136,134,132,130,128,128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,201,203,205,207,209,211,213,215,217,219,221,223,225,227,229,231,233,235,237,239,241,243,245,247,249,251,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
const PROGMEM byte PARTICULAR3[500] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,128,130,133,136,139,142,144,147,150,153,156,158,161,164,167,170,172,175,178,181,184,186,189,192,195,197,200,203,206,209,211,214,217,220,223,225,228,231,234,237,239,242,245,248,251,253,249,244,238,233,227,221,216,210,205,199,193,188,182,177,171,165,160,154,149,143,137,132,126,121,115,109,104,98,93,87,81,76,70,65,59,53,48,42,37,31,25,20,14,9,3,1,2,3,5,6,8,9,10,12,13,15,16,17,19,20,22,23,24,26,27,29,30,31,33,34,36,37,38,40,41,43,44,45,47,48,50,51,52,54,55,57,58,59,61,62,64,65,66,68,69,71,72,73,75,76,78,79,80,82,83,85,86,87,89,90,92,93,94,96,97,99,100,101,103,104,106,107,108,110,111,113,114,115,117,118,120,121,122,124,125,127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void setup()
{
   Serial.begin(9600);
   transmision.begin(9600);
   pinMode(boton,INPUT);
   DDRD = 0b11111111;
}

void loop()
{
  lectura=digitalRead(boton);
  if(lectura!=estadoback)
  {
    if(lectura==HIGH)
    {
      contador++;
      transmision.println(contador);
    }
  }
  estadoback=lectura;
  if(contador>10)
  {
    contador=0;
  }
 switch(contador)
   {
   case 1:
   for(int i=0; i<500; i++)
   {
   PORTD=pgm_read_word(&SENOIDAL[i]);
   delayMicroseconds(100);   
   }
   break;
   case 2:
   for(int i=0; i<500; i++)
   {
   PORTD=pgm_read_word(&EXPOCRE[i]);
   delayMicroseconds(100);
   }
   break;
   case 3:
   for(int i=0; i<500; i++)
   {
   PORTD=pgm_read_word(&AMORTEX[i]);
   delayMicroseconds(100);
   }
   break;
   case 4:
   for(int i=0; i<500; i++)
   {
   PORTD=pgm_read_word(&CUADRADA[i]);
   delayMicroseconds(100);
   }
   break;
   case 5:
   for(int i=0; i<500; i++)
   {
   PORTD=pgm_read_word(&TRIANGULO[i]);
   delayMicroseconds(100);
   }
   break;
   case 6:
   for(int i=0; i<500; i++)
   {
   PORTD=pgm_read_word(&SIERRA[i]);
   delayMicroseconds(100);
   }
   break;
   case 7:
   for(int i=0; i<500; i++)
   {
   PORTD=pgm_read_word(&SINC[i]);
   delayMicroseconds(100);
   }
   break;
   case 8:
   for(int i=0; i<500; i++)
   {
   PORTD=pgm_read_word(&PARTICULAR1[i]);
   delayMicroseconds(100);
   }
   break;
   case 9:
   for(int i=0; i<500; i++)
   {
   PORTD=pgm_read_word(&PARTICULAR2[i]);
   delayMicroseconds(100);
   }
   break;
   case 10:
   for(int i=0; i<500; i++)
   {
   PORTD=pgm_read_word(&PARTICULAR3[i]);
   delayMicroseconds(100);
   }
   break;
   default:
   break; 
}
}
 
