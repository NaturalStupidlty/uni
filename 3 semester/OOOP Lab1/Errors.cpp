#include "Errors.h"

const int CAN_NOT_ADD_EDGE_ERROR_CODE = 1;
const int CAN_NOT_CREATE_GRAPH_ERROR_CODE = 2;

const char* CAN_NOT_LOAD_ADD_EDGE_ERROR_TEXT = "CAN'T ADD THIS EDGE TO THE GRAPH";
const char* CAN_NOT_CREATE_GRAPH_ERROR_TEXT = "CAN'T CREATE THIS KIND OF A GRAPH";

map<int, const char*> ERRORS_MAP =
{
    {CAN_NOT_ADD_EDGE_ERROR_CODE, CAN_NOT_LOAD_ADD_EDGE_ERROR_TEXT},
};

void printError(int error)
{
    cout << "ERROR " << error << ": " << ERRORS_MAP[error] << endl;
}