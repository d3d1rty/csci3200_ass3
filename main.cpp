#include <iostream>
#include <string>
#include <vector>

#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>

using namespace xercesc;
using namespace std;

int main() {
    try {
        XMLPlatformUtils::Initialize();
    } catch (const XMLException &exception) {
        cout << "Unable to initialize the parser.\n";
        return 1;
    }
    cout << "this is a test\n";
    return 0;
}
