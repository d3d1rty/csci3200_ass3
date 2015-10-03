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

class MySAXHandler : public DefaultHandler {

};

int main() {
    // tries to initialize the xml parser
    try {
        XMLPlatformUtils::Initialize();
    } catch (const XMLException &exception) {
        // catches error is unable to initialize parser and returns 1
        cout << "Unable to initialize the parser.\n";
        return 1;
    }

    string xmlFilename = "mondial-3.0.xml";

    // creates the parser object and sets validation and namespaces to true
    SAX2XMLReader *parser = XMLReaderFactory::createXMLReader();
    parser->setFeature(XMLUni::fgSAX2CoreValidation, true);
    parser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);

    // creates the handler object and sets it to handle content and errors
    MySAXHandler handler = new MySAXHandler();
    parser->setContentHandler(handler);
    parser->setErrorHandler(handler);

    try {
        parser->parse(xmlFilename.c_str());
    } catch (const XMLException &ex) {
        // catches XML related errors, cleans up pointers, returns 1
        cout << "Unexpected error occurred\n";
        delete parser;
        delete handler;
        return 1;
    } catch (const SAXParseException &ex) {
        // catches parser related errors, cleans up pointers, returns 1
        cout << "Unexpected error occurred\n";
        delete parser;
        delete handler;
        return 1;
    } catch (...) {
        // catches all other unanticipated errors, cleans up pointers, returns 1
        cout << "Unexpected error occurred\n";
        delete parser;
        delete handler;
        return 1;
    }

    // cleans up pointers and ends program successfully
    delete parser;
    delete handler;
    return 0;
}
