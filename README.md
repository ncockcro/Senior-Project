# Senior-Project

For my Computer Science capstone, I decided to recreate the popular educational game *Oregon Trail*! This is a semester long project where I am demonstrating the knowledge and information that I have gained during my time at Ramapo College of New Jersey. This game is written in C++ and was built using Visual Studio as the developing environment. 

### Oregon Trail

Oregon Trail was originally developed in 1971 by Don Rawitsch, Bill Heinemann, and Paul Dillenberger. At the time, it was a simple text based strategy game that was designed to teach kids about the 19th century pioneer life on the Oregon Trail. The game garnered massive success in the 70s and 80s and would go on to be one of the most historic games in gaming history. There have been several iterations of the game since then, spanning many different platforms, including mobile. My version of Oregon Trail will be sticking closely to the earlier versions of the game as well as adding a few more modern features such as leaderboards, a ranking system, along with a store where players are able to purchase useful items.

### Setup
When the game first boots up, players are greated by a welcome screen with several options, this is the main menu.  Users can start a new game, get a description of what the game is about, check the leaderboards, and exit the application. 

### Actual Trail

Once entering into a new game, the player is asked to pick what their profession is. They have the option to start off as a banker, carpenter, or farmer which each start out with $1600, $800, and $400 respectively. Then the player is asked for the names of their party members and which month to leave from. The month they leave has an impact on some of the random conditions they may encounter in the game. For example, if they leave in March, the party will be more susceptible to blizzards which will cause the player to lose the trail for a couple days and go through their food more quickly due to the cold weather. After these choices are made, you stop by Matt's general store to pick up supplies for the trip. Finally your off! Your path goes as follows:

Independence --> Kansas River crossing --> Big Blue River crossing --> Fort Kearney --> Chimney Rock --> Fort Laramie -->
Independence Rock --> South Pass --> Green River OR Fort Bridger --> Soda Springs --> Fort Hall --> Snake River -->
Fort Boise --> Blue Mountains --> Fort Walla Walla --> The Dalles --> Willamette Valley

Through this path the player will encounter random events such as disease, thieves, blizzards, lack of water, and much more. However, once the player makes it to Willamette Valley, they made it to Oregon and the game is over. The player's score is shown and then they are taken back to the main menu.

### Trail Menu
Every time the player stops at a location, they have several options available to them by the trail menu. In the menu, the player can:

- Check the supplies that they own
- Look at the map to see where they have been and where they have to go
- Change the pace the player is travelling at
- Change the rate that the party members eat food
- Stop to rest
- Talk to people
- Either buy supplies OR hunt (depending on the location)

### Map
When the player stops at a location, they have the option to look at the map and see which locations they have been to and which ones they need to go to. The locations in green mean they have been visited and the ones in red are the ones the player still needs to go to.

### Player's Pace
The player has the option to change the pace at which they travel at. They have the options of steady, streneuous, and grueling. Steady will keep the player's party healthy and travel at a moderate amount of miles. Steneuous picks up the pace from steady and will negatively impact the party's health but not by much. Grueling will allow the player to travel more per day but will greatly hurt the player's overal party health.

### Player's Food Rate
The player has the option to change how much food the party will eat. per day. They have the options of filling, meager, and bare bones. Filling will give three pounds of food to each party member and will ensure that the party stays healthy. Meager will give two pounds of food to each party member and will slightly keep the party healthy. Bare bones will only give one pound of food to each party member and this will negatively impact the party's health.

### Rest
At a location, the player has the option to rest which still has the player's party eat food for every day they rest, but, the party will regain health as long as the player has enough food for the rest.

### Dialogue
As the player travels across the trail, there are various people to talk to at all of the locations in the game. These people offer helpful tips that can lead the player in the right direction to surviving the Oregon Trail.

### Stores
As mentioned earlier, before you leave for your travels you have the oppertunity to visit Matt's general store where you can buy supplies for your trip but there are also several stores that can be found at the various forts along the path. However, the farther out you are from Independence, Missouri, the more expensive the goods become.

### Hunting
Throughout the trail, the player has the option to hunt for food when there is no store at a particular location. It is an available option for the player if they would like to partake. Hunting involves the folling:

- Randomly chooses the amount of animals each time to hunt for food
- The user needs to type either "Bang" or "Pow" in a certain amount of time to be rewarded food
- The amount of time the player has to type in the word can vary
-  The amount of food is calculated each time by 5 * the amount of extra seconds the player had to type in the hunting word

### End of Game
The game can end in one of two ways. The first way, is that the player is successful in reaching Oregon, and they have completed the trail. The other way, is if all of the party members died on the trail, some time along the way. A party member dies when they have three or more diseases. Party members can be more susceptible to getting a disease if the party's health overall is in critical condition. 

### Leaderboard
The leaderboard is accessible through the main menu and when chosen, will display the top 10 players who have played locally on the machine that the game is played on. 

### Scoring
You must complete the entirety of the Oregon trail in order to recieve any points that contribute to your overall score. Once you have completed a trail, you get a multiplier depending on the position you chose at the beginning of the game. The multiplies are as follows:

- Banker - 1x multiplier
- Carpenter - 2x multiplier
- Farmer - 3x multiplier

Along with the multiplies, the scoring is determined by these factors:

- 500 points for every party member that survives and your team is in "good" health
- 400 points for every party member that survives and your team is in "fair" health
- 300 points for every party member that survives and your team is in "poor" health
- 200 points for every party member that survives and your team is in "very poor" health

- 50 points for just having your wagon
- 4 points for each oxen
- 2 points for each spare wagon part
- 2 points for each set of clothing
- 1 point for each multiple of 50 bullets
- 1 point for each multiple of 25 pounds of food
- 1 point for every $5
