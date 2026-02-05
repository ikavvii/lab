package com.example;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.stage.Stage;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class UserEntryApp extends Application {

    private static final String DB_URL = "jdbc:oracle:thin:@orcl:1521:ORCL";
    private static final String DB_USER = "g123";
    private static final String DB_PASS = "g123";

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Oracle DB - Add User");

        // --- UI Components ---
        Label headerLabel = new Label("Register New User");
        headerLabel.setFont(Font.font("Arial", FontWeight.BOLD, 20));

        Label nameLabel = new Label("Username:");
        TextField nameInput = new TextField();
        nameInput.setPromptText("Enter username");

        Label emailLabel = new Label("Email:");
        TextField emailInput = new TextField();
        emailInput.setPromptText("Enter email address");

        Button submitButton = new Button("Save to Database");
        Label statusLabel = new Label(); // Displays success or error messages

        // --- Layout (GridPane) ---
        GridPane grid = new GridPane();
        grid.setAlignment(Pos.CENTER);
        grid.setHgap(10);
        grid.setVgap(10);
        grid.setPadding(new Insets(20, 20, 20, 20));

        grid.add(nameLabel, 0, 0);
        grid.add(nameInput, 1, 0);
        grid.add(emailLabel, 0, 1);
        grid.add(emailInput, 1, 1);
        grid.add(submitButton, 1, 2);

        // Main Container
        VBox root = new VBox(20);
        root.setAlignment(Pos.CENTER);
        root.getChildren().addAll(headerLabel, grid, statusLabel);

        // --- Event Handling ---
        submitButton.setOnAction(e -> {
            String username = nameInput.getText();
            String email = emailInput.getText();

            // Simple Validation
            if (username.isEmpty() || email.isEmpty()) {
                statusLabel.setText("Please fill in all fields.");
                statusLabel.setTextFill(Color.RED);
            } else {
                // Call Database Method
                boolean success = insertData(username, email);

                if (success) {
                    statusLabel.setText("Success! User added to DB.");
                    statusLabel.setTextFill(Color.GREEN);
                    nameInput.clear();
                    emailInput.clear();
                } else {
                    statusLabel.setText("Database Connection Failed. Check Console.");
                    statusLabel.setTextFill(Color.RED);
                }
            }
        });

        // --- Scene Setup ---
        Scene scene = new Scene(root, 400, 350);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    // --- JDBC Logic ---
    private boolean insertData(String username, String email) {
        String sql = "INSERT INTO users (username, email) VALUES (?, ?)";

        // Try-with-resources ensures the connection closes automatically
        try (Connection conn = DriverManager.getConnection(DB_URL, DB_USER, DB_PASS);
             PreparedStatement stmt = conn.prepareStatement(sql)) {

            // Bind values to the query to prevent SQL Injection
            stmt.setString(1, username);
            stmt.setString(2, email);

            int rowsInserted = stmt.executeUpdate();
            return rowsInserted > 0;

        } catch (SQLException ex) {
            System.err.println("Database Error: " + ex.getMessage());
            ex.printStackTrace();
            return false;
        }
    }
}