# RPGForge

## About
The **RPGForge** project has the purpose of not only being an RPG game, but, above all, being **a tool where RPGs can be built**. First of all, this is a **personal project**, so I have no intention of convincing you to use it. However, **I would really appreciate your feedback**, both to improve the program and, honestly, for my own personal satisfaction.

**So, why use this instead of RPG Maker or something similar?**
1. RPGForge's main inspiration comes from tabletop RPGs such as Dungeons & Dragons. This means that the focus is on role-playing and creating a story, not just playing a game (although it is a game too). There will be many tools to offer different possibilities for giving more depth to NPCs, dialogues and narration.
2. You should know C++ or at least the basics of programming logic, so it should not be too difficult to use the tool, especially because there will eventually be a guide on how to create your own campaigns. The whole tool is designed around customizable, practical and easy-to-edit campaigns. You might even learn programming with it.

## Origin
The idea for this project came a long time ago, since I started programming and consequently started using the terminal. I remember having this "vibe" — I don't know exactly where it came from — of text-based RPGs running in the terminal. I have always found this aesthetic interesting. Now that I am learning C++, I want to use this project as a tool to further develop my programming skills.

## Campaigns
As the main inspiration for this project is TTRPGs, when you use the tool, you will create a "Campaign". A Campaign is the main entry point of an adventure, where the adventure itself will run. RPGForge provides the systems and tools needed to build an RPG, while the Campaign is what uses those systems to create a specific adventure. Each Campaign can have its own characters, NPCs, dialogues, locations, dungeons, quests, rules and story. This allows different RPGs to be built and played using the same RPGForge.

## Roadmap
*This roadmap is not a strict plan. Features and versions may change as the project develops.*

### 0.1 — Tool Root
The first version will focus on the fundamental modules of RPGForge.

### Features
* **HUD module:** will provide simple UI functions to make development easier and create understandable interfaces.
* **Entities module:** will store information about monsters and players, such as attributes, HP and inventory, as well as basic functions related to entities, such as `pick_item()`, `damage()` and `heal()`.

### 0.2 — Adventure Places
The concept of Adventure Place is very generic, but simple to understand. An Adventure Place, or AP, is divided into areas. Each area can have a certain type of monster, loot, or anything else. Every AP has some kind of danger. Translate danger into whatever you want in your universe, but danger is one of the ways to create tension.

This concept is briefly defined this way because the tool is scenario-agnostic, so it can be used for any scenario (Sci-Fi, Medieval Fantasy, Horror and many others).

#### Features:
* **Combat module:** will provide simple turn-based combat with HP, damage and item usage.
* **Create Character Presets:** the tool user will be able to create their own preset characters and make them available to the player. Many other features, such as skills, special abilities, races and classes, will not be here yet, or may change later.
* **Create Dungeons:** the tool user will also be able to create their own dungeon presets. The experience of creating them may still be somewhat difficult, but with feedback I will improve it to make the process easier for developers.
* **Sample Characters:** these characters are inspired by HeroQuest (one of the predecessors of common medieval fantasy TTRPGs). We will offer character options to choose from, each one having their own focus:
    * The Elf (+Skills)
    * The Dwarf (+Defense)
    * The Barbarian (+Damage)
    * The Mage (+Magic)
* **Sample Dungeon:** the player will be able to play through a simple dungeon from a fantasy scenario, going from one room to another and fighting monsters. There will be no real loot, XP or saves yet. The idea is simply to play the dungeon with one character and discard the session afterwards, but the player can always test other characters.

### 0.3 — Full Dungeon Sample
#### Features:
* **Character Progression:** the player will be able to select a character and play through the dungeon from the 0.2 Medieval Fantasy sample. This time, the player will be able to collect loot and gain XP, but the character level will be limited to 5 (which the player will probably reach by the end of the dungeon).
* **Refining Adventure Place Creation:** with the addition of the sample dungeon levels, some new functions may also be added to make this process easier.
* **Game Saves:** progress will be saved, allowing the player to open the game again, load the same save and continue exploring.
* **Bigger Sample Dungeon:** the dungeon will have more levels and eventually a boss fight. The expectation is that the player will reach level 5 — or something close to it — by the end of the dungeon. A "dungeon score system" will also be added — probably just for this version — allowing the player to try to surpass their previous score.

### 0.4 — City System
A city system that will add depth to the world — it is not just a dungeon, there is a whole world around it. This step will add greater depth to the world and improve the "RP" part of the tool. This build will also offer a city sample to test it out.

### Features
* **City Sample:** the player will start by arriving in a city and will have to find their way to the dungeon (the same one from the 0.3 build). The city will be preset and will contain NPCs, shops and rumors about the dungeon and other random things. There will be at least three ways to find the dungeon, introducing more role-playing and choice into the game: do what your character would do.
* **Personality System:** just an idea for now, so this may also be introduced. Each character could have their own personality, unlocking new dialogue options based on it. This is still just an idea and will be evaluated when development reaches this point.

### 0.5 — Dungeon & City Expansion
Not really a major new build, but rather an expansion of the sample campaign. I will focus on offering a better experience, support, and more powerful and easier-to-use tools for users.

### Features
* **Expanded Sample:** the same scenario will be expanded with more city and dungeon lore, new NPCs and side quests. Two new dungeons with different themes will also be added.
* **Maximum Level Expanded to 10:** with this change, more character progression will come.

### 0.6 — Character Expansion
More character customization through race, class, past, skills, proficiencies and many other things. With this comes character creation!

### Features
* **Expanded Character Features:** old character presets only contain HP, MP, some skills, proficiencies and some abilities, but this is all rigid. After this build, all these concepts will change depending on the character's race, class and past, among other factors. This will offer a more complex and customizable character.
* **Character Creation:** with the expanded character system, it would be illogical if the player could not create a character! The player will be able to create their own character by choosing a race, class, past, distributing their ability points and choosing a personality. These choices will provide different skills and characteristics. The player will also be able to give their character a name!
* **New Character Progression:** as progression will no longer be tied to one single character, it will now be attributed especially to the class, offering new special abilities throughout progression. The race will also provide one initial special ability.

### 0.7 — World Update
The world is not limited by the darkness of dungeons or city walls. Go beyond! After this update, players will be able to explore the world outside cities in a pointcrawl style.

#### Features
* **Expanded World:** the player will be able to explore not only the city and the dungeons, but also the world around them. They will be able to hear rumors about the world, visit points of interest and encounter new enemies and monsters in the wild.
* **Sample Character Levels Expanded to 15:** with this change, more character progression will come.

### 0.8 — Final Polishing
The main focus will be on improving, polishing and integrating the systems created throughout the previous versions. This version will focus on making the existing systems more stable and cohesive rather than simply adding more content.

### 1.0 — First Stable Build
The first stable build of RPGForge. This version will include a guide for creating your own campaigns, allowing other users to understand the structure of the project and start building their own RPGs using RPGForge.

## Versioning
RPGForge uses MAJOR.MINOR.PATCH versioning. MAJOR represents major or breaking changes, MINOR represents new features or systems, and PATCH represents small fixes and improvements. Git tags will be used to mark versions, while branches will be used for individual features and fixes.

**Current version:** 0.1.0

**Status:** Early Development

*This roadmap is not a strict plan. Features and versions may change as the project develops.*
