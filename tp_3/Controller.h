int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromTextFlight(char* path , LinkedList* pArrayListFlights);

int controller_addPassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayListFlight, int* id);
int controller_editPassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayListFlight);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_sortPassengerId(LinkedList* pArrayListPassenger, int order);
int controller_sortPassengerName(LinkedList* pArrayListPassenger, int order);
int controller_sortPassengerLastname(LinkedList* pArrayListPassenger, int order);
int controller_sortPassengerPrice(LinkedList* pArrayListPassenger, int order);
int controller_sortPassengerType(LinkedList* pArrayListPassenger, int order);
int controller_sortPassengerFlightCode(LinkedList* pArrayListPassenger, int order);
int controller_sortPassengerStatus(LinkedList* pArrayListPassenger, int order);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

int controller_loadStatusFlight(LinkedList* pArrayListFlight, char* flightCode, int* statusFlight);
int controller_isValidFlightCode(LinkedList* pArrayListFlight, char* flightCode);
int controller_inputFlightCode(LinkedList* pArrayListFlight, char* flightCode);

int controller_searchIdPasajero(LinkedList* pArrayPassenger, int id, int* index);
int controller_isPassengerIdValid(LinkedList* pArray, int id);
int controller_inputIdPassenger(LinkedList* pArray, int* id);

int controller_editMenu_option();
void controller_editMenu(LinkedList* pArrayPassenger, LinkedList* pArrayFlight);

int controller_sortMenuOption();
void controller_sortMenu(LinkedList* pArray);

int controller_menu_option();
void controller_Menu(LinkedList* pArrayListPassenger, LinkedList* pArrayListFlight);

int controller_ListFlight(LinkedList* pArrayListFlight);
int controller_getMaxId(LinkedList* pArray, int* id);


