package com.example;

import jakarta.xml.ws.Endpoint;

public class SoapServer {
    public static void main(String[] args) {
        String url = "http://localhost:8080/ws/hello";

        System.out.println("Starting SOAP Server at: " + url);
        System.out.println("View WSDL at: " + url + "?WSDL");

        // Publishes the SOAP Web Service
        Endpoint.publish(url, new HelloWorldImpl());
    }
}