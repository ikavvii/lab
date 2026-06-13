package com.example;

import jakarta.jws.WebMethod;
import jakarta.jws.WebService;

@WebService(targetNamespace = "https://example.com/ws")
public interface HelloWorld {

    @WebMethod
    String sayHello(String name);
}