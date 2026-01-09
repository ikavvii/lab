package com.example.demo.controller;


import com.example.demo.entity.ProductEntity;
import com.example.demo.repository.ProductRepository;
import org.springframework.web.bind.annotation.*;

import java.time.LocalDateTime;
import java.util.Optional;

@RestController
@RequestMapping("/products")
public class ProductController {

    private final ProductRepository productRepository;

    public ProductController(ProductRepository productRepository) {
        this.productRepository = productRepository;
    }

    @PostMapping()
    public ProductEntity create(@RequestBody ProductEntity productEntity) {
        productEntity.setCreatedAt(LocalDateTime.now());
        return productRepository.save(productEntity);
    }

    @GetMapping("/{id}")
    public ProductEntity getById(@PathVariable Long id) {
        Optional<ProductEntity> optional = productRepository.findById(id);
        return optional.orElse(null);
    }
}
