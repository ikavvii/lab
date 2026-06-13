package com.example;

import jakarta.jws.WebService;

@WebService(
        endpointInterface = "com.example.HelloWorld",
        targetNamespace = "https://example.com/ws",
        serviceName = "HelloWorldService"
)
public class HelloWorldImpl implements HelloWorld {

    @Override
    public String sayHello(String name) {
        return "Hello, " + name + "! Welcome to SOAP.";
    }
}