<?php

class ScartDB {

    private $servername = "localhost";
    private $username = "root";
    private $password = "";
    private $db_name = "scproject";
    private $db;
    
    function connect() {
        $this->db = new mysqli(
            $this->servername,
            $this->username,
            $this->password,
            $this->db_name
        );
        
        if ($this->db->connect_error) {
            die("Connection failed: " . $this->db->connect_error);
        }
    }
    
    function disconnect() {
        if ($this->db) {
            $this->db->close();
        }
    }

    public function getDbConnection() {
        return $this->db;
    }

    public function getAllUsers() {
        $query = "SELECT id_user, username, password FROM users";
        $result = $this->db->query($query);

        $users = [];
        if ($result->num_rows > 0) {
            while ($row = $result->fetch_assoc()) {
                $users[] = $row;
            }
        }
        return $users;
    }
    
    function checkUserExists($username) {
        $query = "SELECT * FROM `".$this->db_name."`.`users` AS `users` WHERE `username` = '".$username."'";
        return (bool)$this->db->query($query)->fetch_assoc();
    }
    
    function getCategories() {
        $query = "SELECT DISTINCT category FROM items";
        return $this->db->query($query)->fetch_all(MYSQLI_ASSOC);
    }
    
    function getUser($username) {
        $query = "SELECT `id_user` AS `USER_UID`, `username` AS `USERNAME`, `password` AS `PASSWORD` FROM `".$this->db_name."`.`users` AS `users` WHERE `username` = '".$username."'";
        return $this->db->query($query)->fetch_assoc();
    }
    
    function addUser($username, $password) {
        $query = "INSERT INTO `".$this->db_name."`.`users` (`username`, `password`) VALUES ('".$username."', '".$password."')";
        $this->db->query($query);
    }
    
    function getItemsByCategory($category) {
        $query = "SELECT `id_item`, `name`, `price`, `category` FROM `items` WHERE `category` = '".$this->db->real_escape_string($category)."'";
        $result = $this->db->query($query);

        $items = [];
        if ($result->num_rows > 0) {
            while ($row = $result->fetch_assoc()) {
                $items[] = $row;
            }
        }
        
        return $items;
    }
    
    public function getAllSales() {
        $query = "SELECT name, SUM(price) AS total_sales FROM sales GROUP BY name";
        $result = $this->db->query($query);

        $sales = [];
        if ($result->num_rows > 0) {
            while ($row = $result->fetch_assoc()) {
                $sales[] = $row;
            }
        }
        return $sales;
    }
}

