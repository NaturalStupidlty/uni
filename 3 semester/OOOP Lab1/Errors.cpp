#include "Errors.h"

const int CANNOT_CREATE_GRAPH_ERROR_CODE = 1;
const int CANNOT_ADD_EDGE_ERROR_CODE = 2;

const char* CANNOT_CREATE_GRAPH_ERROR_TEXT = "CAN'T CREATE THIS KIND OF A GRAPH";
const char* CANNOT_LOAD_ADD_EDGE_ERROR_TEXT = "CAN'T ADD THIS EDGE TO THE GRAPH";


map<int, const char*> ERRORS_MAP =
{
    {CANNOT_ADD_EDGE_ERROR_CODE, CANNOT_LOAD_ADD_EDGE_ERROR_TEXT},
};

void printError(int error)
{
    cout << "ERROR " << error << ": " << ERRORS_MAP[error] << endl;
}