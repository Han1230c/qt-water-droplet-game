# Water Droplet Game

A Qt-based game where players catch water droplets in a bucket.

## Project Overview

This game was developed as part of a software engineering course project. It demonstrates proficiency in C++, Qt framework, object-oriented design, and basic game development concepts.

### Key Features

- User authentication system with registration and login
- Multiple difficulty levels
- Score tracking and history
- Responsive game controls
- Collision detection
- Dynamic difficulty scaling

## Technical Stack

- Language: C++
- Framework: Qt 6.7.0
- Build System: qmake
- Version Control: Git

## Architecture

The project follows an object-oriented design with key classes including:

- `GameScene`: Main game logic and rendering
- `Droplet`: Represents falling water droplets
- `Bucket`: Player-controlled catching mechanism
- `User`: Manages user data and authentication

## Code Highlights

- Implemented a custom event system for game state changes
- Utilized Qt's signal-slot mechanism for loose coupling between components
- Designed a flexible difficulty system that can be easily extended

## Learning Outcomes

- Gained experience with Qt for cross-platform GUI development
- Improved understanding of game loop and frame-rate independent movement
- Practiced implementing user authentication and data persistence
- Enhanced skills in object-oriented design and C++ programming

## Future Improvements

- Add multiplayer functionality
- Implement power-ups and obstacles
- Create a level editor for user-generated content

## How to Run

1. Ensure Qt 6.7.0 or later is installed
2. Clone the repository
3. Open the project in Qt Creator
4. Build and run the project