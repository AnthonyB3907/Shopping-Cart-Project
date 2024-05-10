#include "pop.h"

Pop::Pop()
{
    std::fstream itemFile;
    
    flag = false;
    bool isEmpty = true;
    
    while(!flag) // loops until file is opened succesfully. file created if it doesnt exist
    {
        // ios::in by itself reads from the start. if file doesnt exist, error
        itemFile.open("items.bin", std::ios::in | std::ios::binary);
        if (!itemFile)
        {
            itemFile.open("items.bin", std::ios::out | std::ios::binary);
            itemFile.close();
            flag = false;
        }
        else if (itemFile) // checks if items.bin is empty
        {
            flag = true;
            itemFile.seekg(0L, std::ios::end);
            int numBytes = itemFile.tellg();
            if (numBytes > 0)
                isEmpty = false;
        }
        itemFile.close();
    }
    
    if (isEmpty) // write to file only if items.bin is empty
    {
        itemFile.open("items.bin", std::ios::binary | std::ios::out | std::ios::app);
    
        Item items[80] = {{1, 3.68, "Cereal (10.8oz box)", 0}, {1, 13.53, "Water Bottles (24 pack)", 0}, {1, 6.00, "Soda (10 cans)", 0}, {1, 14.39, "Rib-Eye Steak (1lb)", 0},
                         {1, 2.79, "Sour Cream & Onion Chips", 0}, {1, 5.59, "Butter", 0}, {1, 6.09, "Teriyaki Marinade", 0}, {1, 3.89, "White Bread", 0},
                         {1, 4.49, "Bag of Potatoes", 0}, {1, 5.59, "Milk (1 gal)", 0}, {2, 6.31, "Toilet Paper", 0}, {2, 14.96, "Trash Bags", 0},
                         {2, 12.47, "Disinfecting Wipes", 0}, {2, 9.99, "Microfiber Cloths (20 pack)", 0}, {2, 19.99, "Paper Towels (12 rolls)", 0}, {2, 17.50, "Dish Soap Spray", 0},
                         {2, 4.48, "Aluminum Foil", 0}, {2, 10.41, "Air Freshener (3 pack)", 0}, {2, 23.99, "Broom and Dustpan Set", 0}, {2, 11.19, "Toothpaste (4 pack)", 0},
                         {3, 49.98, "Dog Food (30lb bag)", 0}, {3, 8.99, "Dog Toy", 0}, {3, 14.99, "Dog Leash", 0}, {3, 17.46, "Cat Food (24 pack)", 0},
                         {3, 9.99, "Cat Toy", 0}, {3, 14.99, "Cat Litter", 0}, {3, 499.99, "Self-Cleaning Cat Box", 0}, {3, 18.41, "Bird Feed (10lb", 0},
                         {3, 25.44, "Bird Cage", 0}, {3, 4.99, "Fish Food", 0}, {4, 69.99, "Wood Desk", 0}, {4, 24.99, "Desk Chair", 0},
                         {4, 199.99, "Kitchen Table", 0}, {4, 14.99, "Kitchen Chair", 0}, {4, 399.99, "Mattress", 0}, {4, 5.99, "Pillows", 0},
                         {4, 299.99, "Couch", 0}, {4, 69.99, "Dresser", 0}, {4, 39.99, "Bookshelf", 0}, {4, 49.99, "TV Stand", 0},
                         {5, 42.99, "Cordless Drill", 0}, {5, 39.99, "Circular Saw", 0}, {5, 34.99, "Angle Grinder", 0}, {5, 29.99, "15-Piece Wrench Set", 0},
                         {5, 16.99, "Utility Knife", 0}, {5, 9.99, "18 in 1 Screwdriver", 0}, {5, 10.99, "Pliers", 0}, {5, 6.79, "Wire Cutter", 0},
                         {5, 13.99, "30 Piece Allen Wrench Set", 0}, {5, 35.99, "Tool Box Organizer", 0}, {6, 14.99, "Spider-Man 2", 0}, {6, 14.99, "Avengers: Infinity War", 0},
                         {6, 14.99, "Oppenheimer", 0}, {6, 14.99, "Dune", 0}, {6, 14.99, "Barbie", 0}, {6, 14.99, "Interstellar", 0},
                         {6, 14.99, "Saving Private Ryan", 0}, {6, 14.99, "Hacksaw Ridge", 0}, {6, 14.99, "Avengers: Endgame", 0}, {6, 14.99, "Top Gun: Maverick", 0},
                         {7, 399.99, "144Hz Monitor", 0}, {7, 549.99, "4070 Graphics Card", 0}, {7, 149.99, "CPU", 0}, {7, 89.99, "32GB RAM (16x2)", 0},
                         {7, 114.99, "Power Supply", 0}, {7, 97.99, "Solid State Drive", 0}, {7, 49.99, "Gaming Mouse", 0}, {7, 15.99, "Keyboard", 0},
                         {7, 199.99, "Motherboard", 0}, {7, 119.99, "Speakers", 0}, {8, 29.99, "Call of Duty", 0}, {8, 29.99, "World of Warcraft", 0},
                         {8, 29.99, "Path of Exile", 0}, {8, 29.99, "Fortnite", 0}, {8, 29.99, "Minecraft", 0}, {8, 29.99, "Guild Wars 2", 0},
                         {8, 29.99, "Last Epoch", 0}, {8, 29.99, "Slay the Spire", 0}, {8, 29.99, "Elden Ring", 0}, {8, 29.99, "Diablo IV", 0}};
    
        itemFile.write(reinterpret_cast<char*>(items), 80 * sizeof(Item));
        itemFile.close();
    }
    
}