/*******************
Copyright 2015 Richard Davis
CSCI 3020 Section W1
Fall 2015
Assignment 3
Programmed on Arch Linux (kernel version 4.1.6-1-ARCH) using g++ (v5.2.0)
This program uses a SAX parser to extract information from an XML document
*******************/

#include <iostream>
#include <string>
#include <vector>
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>

using namespace xercesc;
using namespace std;

// creates the MySAXHandler class which extends the DefaultHandler class
class MySAXHandler : public DefaultHandler {
private:
    // declares variables needed for parsing the file
    bool success;
    bool inCountry;
    bool inCountryName;
    bool inCity;
    bool inCityName;
    bool inReligion;

    // prototypes the methods which will be overloaded
    void startElement(const XMLCh* const uri, const XMLCh* const localname, const XMLCh* const qname, const Attributes& attrs);
    void endElement(const XMLCh* const uri, const XMLCh* const localname, const XMLCh* const qname);
    void characters(const XMLCh* const chars, const XMLSize_t length);
    void fatalError(const SAXParseException& ex);

public:
    // overloads the default constructor for the MySAXHandler() object
    MySAXHandler() {
        success = true;
        bool inCountry = false;
        bool inCountryName = false;
        bool inCity = false;
        bool inCityName = false;
        bool inReligion = false;
    }

    // returns the value of the success member variable for error handling purposes
    bool isSuccessful(){
        return success;
    }
};

// overloads the startElement() method inherited from DefaultHandler class
void MySAXHandler::startElement(
    const XMLCh* const uri,
    const XMLCh* const localname,
    const XMLCh* const qname,
    const Attributes& attrs) {
        char *message = XMLString::transcode(localname);

        if (strcmp(message, "country") == 0) {
            inCountry = true;
        } else if (inCountry && !inCity && strcmp(message, "name") == 0) {
            inCountryName = true;
        } else if (inCountry && strcmp(message, "city") == 0) {
            inCity = true;
        } else if (inCity && strcmp(message, "name") == 0) {
            inCityName = true;
        } else if (inCountry && strcmp(message, "religions") == 0) {
            inReligion = true;
        } 

        XMLString::release(&message);
}

// overloads the endElement() method inherited from DefaultHandler class
void MySAXHandler::endElement(
    const XMLCh* const uri,
    const XMLCh* const localname,
    const XMLCh* const qname) {
        char *message = XMLString::transcode(localname);
        if (strcmp(message, "religions") == 0) {
            inReligion = false;
        } else if (inCity && strcmp(message, "name") == 0) {
            inCityName = false;
        } else if (strcmp(message, "city") == 0) {
            inCity = false;
        } else if (inCountry && !inCity && strcmp(message, "name") == 0) {
            inCountryName = false;
        } else if (strcmp(message, "country") == 0) {
            inCountry = false;
        }

        XMLString::release(&message);
}

// overloads the characters() method inherited from DefaultHandler class
void MySAXHandler::characters(
    const XMLCh* const chars,
    const XMLSize_t length) {
        char *message = new char[length + 1];
        XMLString::transcode(chars, message, length);
        if (inCountryName) {
            cout << "COUNTRY: " << message << endl;
        } else if (inCityName) {
            cout << "CITY: " << message << endl;
        } else if (inReligion) {
            cout << "RELIGION: " << message << endl;
        }
        delete [] message;
}

// overloads the fataError() method inherited from DefaultHandler class
void MySAXHandler::fatalError(
    const SAXParseException& ex) {
        char *message = XMLString::transcode(ex.getMessage());
        cout << "Error during parsing: " << message << endl;
        XMLString::release(&message);
        success = false;
}

int main() {
    bool errorOccurred;
    string xmlFilename = "test.xml";

    // tries to initialize the xml parser
    try {
        XMLPlatformUtils::Initialize();
    } catch (const XMLException &exception) {
        // catches error if unable to initialize parser and ends program with error status
        cout << "Unable to initialize the parser.\n";
        return 1;
    }

    // creates the parser object and sets validation and namespaces to true
    SAX2XMLReader *parser = XMLReaderFactory::createXMLReader();
    parser->setFeature(XMLUni::fgSAX2CoreValidation, true);
    parser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);

    // creates the handler object and sets it to handle content and errors
    MySAXHandler *handler = new MySAXHandler();
    parser->setContentHandler(handler);
    parser->setErrorHandler(handler);

    try {
        parser->parse(xmlFilename.c_str());
    } catch (const XMLException &ex) {
        // catches XML related errors
        char *message = XMLString::transcode(ex.getMessage());
        cout << "XML error: " << message << endl;
        XMLString::release(&message);
        errorOccurred = true;
    } catch (const SAXParseException &ex) {
        // catches parser related errors
        char *message = XMLString::transcode(ex.getMessage());
        cout << "Parsing error: " << message << endl;
        XMLString::release(&message);
        errorOccurred = true;
    } catch (...) {
        // catches all other unanticipated errors
        cout << "Unexpected error occurred\n";
        errorOccurred = true;
    }

    if (!handler->isSuccessful() || errorOccurred) {
        // cleans up pointers and ends program with error status
        delete parser;
        delete handler;
        return 1;
    } else {
        cout << xmlFilename << " successfully parsed!\n";
        // cleans up pointers and ends program successfully
        delete parser;
        delete handler;
        return 0;
    }
}
