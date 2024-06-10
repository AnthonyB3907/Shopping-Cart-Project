CREATE DATABASE  IF NOT EXISTS `scproject` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci */;
USE `scproject`;
-- MySQL dump 10.13  Distrib 8.0.36, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: scproject
-- ------------------------------------------------------
-- Server version	5.5.5-10.4.32-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `items`
--

DROP TABLE IF EXISTS `items`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `items` (
  `id_item` int(10) NOT NULL,
  `category` varchar(100) DEFAULT NULL,
  `price` decimal(50,2) DEFAULT NULL,
  `name` varchar(40) DEFAULT NULL,
  PRIMARY KEY (`id_item`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `items`
--

LOCK TABLES `items` WRITE;
/*!40000 ALTER TABLE `items` DISABLE KEYS */;
INSERT INTO `items` VALUES (1,'Grocery',3.68,'Cereal (10.8oz box)'),(2,'Grocery',13.53,'Water Bottles (24 pack)'),(3,'Grocery',6.00,'Soda (10 cans)'),(4,'Grocery',14.39,'Rib-Eye Steak (1lb)'),(5,'Grocery',2.79,'Sour Cream & Onion Chips'),(6,'Grocery',5.59,'Butter'),(7,'Grocery',6.09,'Teriyaki Marinade'),(8,'Grocery',3.89,'White Bread'),(9,'Grocery',4.49,'Bag of Potatoes'),(10,'Grocery',5.58,'Milk (1 gal)'),(11,'House Supplies',6.31,'Toilet Paper'),(12,'House Supplies',14.96,'Trash Bags'),(13,'House Supplies',12.47,'Disinfecting Wipes'),(14,'House Supplies',9.99,'Microfiber Cloths (20 pack)'),(15,'House Supplies',19.99,'Paper Towels (12 rolls)'),(16,'House Supplies',17.50,'Dish Soap Spray'),(17,'House Supplies',4.48,'Aluminum Foil'),(18,'House Supplies',10.41,'Air Freshener (3 pack)'),(19,'House Supplies',23.99,'Broom and Dustpan Set'),(20,'House Supplies',11.19,'Toothpaste (4 pack)'),(21,'Pet Supplies',49.98,'Dog Food (30lb bag)'),(22,'Pet Supplies',8.99,'Dog Toy'),(23,'Pet Supplies',14.99,'Dog Leash'),(24,'Pet Supplies',17.46,'Cat Food (24 pack)'),(25,'Pet Supplies',9.99,'Cat Toy'),(26,'Pet Supplies',14.99,'Cat Litter'),(27,'Pet Supplies',499.99,'Self-Cleaning Cat Box'),(28,'Pet Supplies',18.41,'Bird Feed (10lb)'),(29,'Pet Supplies',25.44,'Bird Cage'),(30,'Pet Supplies',4.99,'Fish Food'),(31,'Furniture',69.99,'Wood Desk'),(32,'Furniture',24.99,'Desk Chair'),(33,'Furniture',199.99,'Kitchen Table'),(34,'Furniture',14.99,'Kitchen Chair'),(35,'Furniture',399.99,'Mattress'),(36,'Furniture',5.99,'Pillows'),(37,'Furniture',299.99,'Couch'),(38,'Furniture',69.99,'Dresser'),(39,'Furniture',39.99,'Bookshelf'),(40,'Furniture',49.99,'TV Stand'),(41,'Tools',42.99,'Cordless Drill'),(42,'Tools',39.99,'Circular Saw'),(43,'Tools',34.99,'Angle Grinder'),(44,'Tools',29.99,'15-Piece Wrench Set'),(45,'Tools',16.99,'Utility Knife'),(46,'Tools',9.99,'18 in 1 Screwdriver'),(47,'Tools',10.99,'Pliers'),(48,'Tools',6.79,'Wire Cutter'),(49,'Tools',13.99,'30 Piece Allen Wrench Set'),(50,'Tools',35.99,'Tool Box Organizer'),(51,'Movies',14.99,'Spider-Man 2'),(52,'Movies',14.99,'Avengers: Infinity War'),(53,'Movies',14.99,'Oppenheimer'),(54,'Movies',14.99,'Dune'),(55,'Movies',14.99,'Barbie'),(56,'Movies',14.99,'Interstellar'),(57,'Movies',14.99,'Saving Private Ryan'),(58,'Movies',14.99,'Hacksaw Ridge'),(59,'Movies',14.99,'Avengers: Endgame'),(60,'Movies',14.99,'Top Gun: Maverick'),(61,'Computer Parts',399.99,'144Hz Monitor'),(62,'Computer Parts',549.99,'4070 Graphics Card'),(63,'Computer Parts',149.99,'CPU'),(64,'Computer Parts',89.99,'32GB RAM (16x2)'),(65,'Computer Parts',114.99,'Power Supply'),(66,'Computer Parts',97.99,'Solid State Drive'),(67,'Computer Parts',49.99,'Gaming Mouse'),(68,'Computer Parts',15.99,'Keyboard'),(69,'Computer Parts',199.99,'Motherboard'),(70,'Computer Parts',119.99,'Speakers'),(71,'Video Games',29.99,'Call of Duty'),(72,'Video Games',29.99,'World of Warcraft'),(73,'Video Games',29.99,'Path of Exile'),(74,'Video Games',29.99,'Fortnite'),(75,'Video Games',29.99,'Minecraft'),(76,'Video Games',29.96,'Guild Wars 2'),(77,'Video Games',29.99,'Last Epoch'),(78,'Video Games',29.99,'Slay the Spire'),(79,'Video Games',29.99,'Elden Ring'),(80,'Video Games',29.96,'Diablo IV');
/*!40000 ALTER TABLE `items` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `sales`
--

DROP TABLE IF EXISTS `sales`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `sales` (
  `id_sales` int(10) NOT NULL AUTO_INCREMENT,
  `category` varchar(10) DEFAULT NULL,
  `price` decimal(50,2) DEFAULT NULL,
  `name` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id_sales`)
) ENGINE=InnoDB AUTO_INCREMENT=35 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `sales`
--

LOCK TABLES `sales` WRITE;
/*!40000 ALTER TABLE `sales` DISABLE KEYS */;
INSERT INTO `sales` VALUES (20,'Furniture',489.93,'Wood Desk'),(21,'Furniture',149.94,'Desk Chair'),(22,'Furniture',1399.93,'Kitchen Table'),(23,'Video Game',119.84,'Diablo IV'),(24,'Furniture',1599.96,'Mattress'),(25,'Computer P',114.99,'Power Supply'),(26,'Computer P',97.99,'Solid State Drive'),(27,'Computer P',49.99,'Gaming Mouse'),(28,'Computer P',15.99,'Keyboard'),(29,'Computer P',199.99,'Motherboard'),(30,'Furniture',29.98,'Kitchen Chair'),(31,'Furniture',279.96,'Dresser'),(32,'Furniture',39.99,'Bookshelf'),(33,'Furniture',49.99,'TV Stand'),(34,'Computer P',2399.94,'144Hz Monitor');
/*!40000 ALTER TABLE `sales` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `users` (
  `id_user` int(10) NOT NULL AUTO_INCREMENT,
  `username` varchar(50) DEFAULT NULL,
  `password` varchar(60) DEFAULT NULL,
  PRIMARY KEY (`id_user`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (4,'admin','$2y$10$Zbi7x7cRQEueMkvLaP8ihub33L5c.X7qcJebPeCIcgklvCpqwnoRS'),(5,'admin1','$2y$10$pHpM6aqV3YXrD7fShroX4e4fK1FFzLUY4hhrg6JLp04QnDniwZYgu'),(6,'anthonyb','$2y$10$QRVVvFhsS0hK0zsQPGxVB.7WJSJHJiDaOOJb8adJEeCB/SNKa1j1.'),(7,'anthonyb123','$2y$10$7BAalDKSnYcfGINlZObr2.O8PRo4iPhKH6R9jJ0IqbNUFV4UhQjri'),(8,'ab123','$2y$10$yaoxrnOwr33Sl28Sw9mRH.4TZFQehuW.UL9dL7bOAUSm9d4wZb8VC'),(9,'ab2436698','$2y$10$RgjKuxXRzUvgnq5Q73K4q.lyqNv7lkuE0EE.U7qZR8jQJZDI455PK'),(10,'hello123','$2y$10$kHvllcwqv/jScav8H/KYo.SzsV6GG2fdPklidd7Gr48L3VFjwMoQC');
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-06-09 22:18:53
