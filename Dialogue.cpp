#include "Dialogue.h"



Dialogue::Dialogue()
{
	srand((unsigned int)time(0));

	m_randomNum = rand() % 3;
}


Dialogue::~Dialogue()
{
}

void Dialogue::TalkToPeople(string a_location) {

	if (a_location == "Independence") {
		Independence();
	}
	else if (a_location == "Kansas River crossing") {
		KRiverCrossing();
	}
	else if (a_location == "Big Blue River crossing") {
		BBlueRiverCrossing();
	}
	else if (a_location == "Fort Kearney") {
		FortKearney();
	}
	else if (a_location == "Chimney Rock") {
		ChimneyRock();
	}
	else if (a_location == "Fort Laramie") {
		FortLaramie();
	}
	else if (a_location == "Independence Rock") {
		IndependenceRock();
	}
	else if (a_location == "South Pass") {
		SouthPass();
	}
	else if (a_location == "Fort Bridger") {
		FortBridger();
	}
	else if (a_location == "Green River") {
		GreenRiver();
	}
	else if (a_location == "Soda Springs") {
		SodaSprings();
	}
	else if (a_location == "Fort Hall") {
		FortHall();
	}
	else if (a_location == "Snake River") {
		SnakeRiver();
	}
	else if (a_location == "Fort Boise") {
		FortBoise();
	}
	else if (a_location == "Blue Mountains") {
		BlueMountains();
	}
	else if (a_location == "Fort Walla Walla") {
		FortWallaWalla();
	}
	else if (a_location == "The Dalles") {
		TheDalles();
	}
	else {
		m_utility.DisplayError("Invalid location for dialogue.");
	}

	if (m_randomNum == 2) {
		m_randomNum = 0;
	}
	else {
		m_randomNum++;
	}

	m_utility.Wait();
}

void Dialogue::Independence() {

	if (m_randomNum == 0) {
		m_utility.OutputMessage("A town resident tells you:");
		cout << endl;
		m_utility.OutputMessage("\"Some folks seem to think that");
		m_utility.OutputMessage("two oxen are enough to get them");
		m_utility.OutputMessage("to Oregon! Tow oxen can barely");
		m_utility.OutputMessage("move a fully loaded wagon, and");
		m_utility.OutputMessage("if one of them gets sick or");
		m_utility.OutputMessage("dies, you won't be going");
		m_utility.OutputMessage("anywhere. I wouldn't go");
		m_utility.OutputMessage("overland with less than six.\"");
	}
	else if (m_randomNum == 1) {
		m_utility.OutputMessage("A trader named Jim tells you:");
		cout << endl;
		m_utility.OutputMessage("\"Better take extra sets of");
		m_utility.OutputMessage("clothing. Trade 'em to Indians");
		m_utility.OutputMessage("for fresh vegetables, fish, or");
		m_utility.OutputMessage("meat. It's well worth hiring");
		m_utility.OutputMessage("an Indian guide at river");
		m_utility.OutputMessage("crossings. Expect to pay them!");
		m_utility.OutputMessage("They're sharp traders, not");
		m_utility.OutputMessage("easily cheated.\"");
	}
	else if (m_randomNum == 2) {
		m_utility.OutputMessage("A traveler, Miles Hendericks,");
		m_utility.OutputMessage("tells you:");
		cout << endl;
		m_utility.OutputMessage("\"Did you read the Missouri");
		m_utility.OutputMessage("Republicans today? --Says some");
		m_utility.OutputMessage("folk start for Oregon without");
		m_utility.OutputMessage("meat. It's well worth hiring");
		m_utility.OutputMessage("carrying spare parts, not even");
		m_utility.OutputMessage("an extra wagon axle. Must");
		m_utility.OutputMessage("think they grow on trees! Hope");
		m_utility.OutputMessage("they're lucky enough to find an");
		m_utility.OutputMessage("abandoned wagon.\"");
	}
	else {
		m_utility.DisplayError("ERROR: Wrong number for dialougue.");
	}
}

void Dialogue::KRiverCrossing() {

	if (m_randomNum == 0) {
		m_utility.OutputMessage("A stranger tells you:");
		cout << endl;
		m_utility.OutputMessage("\"Can't afford to take a ferry.");
		m_utility.OutputMessage("Were making our wagon into a");
		m_utility.OutputMessage("boat. We'll turn it over,");
		m_utility.OutputMessage("caulk the bottom and sides with");
		m_utility.OutputMessage("pitch, and use it to float our");
		m_utility.OutputMessage("goods across. Have to swim the");
		m_utility.OutputMessage("animals. Hope it doesn't rain");
		m_utility.OutputMessage("-- the river's high enough!\"");
	}
	else if (m_randomNum == 1) {
		m_utility.OutputMessage("A ferry operator tells you:");
		cout << endl;
		m_utility.OutputMessage("\"Don't try to ford any river");
		m_utility.OutputMessage("deeper than the wagon bed --");
		m_utility.OutputMessage("about two and half feet.");
		m_utility.OutputMessage("You'll swamp your wagon and");
		m_utility.OutputMessage("lose your supplies. You can");
		m_utility.OutputMessage("caulk the wagon bed and float");
		m_utility.OutputMessage("it -- or be smart and hire me");
		m_utility.OutputMessage("to take your wagon on my");
		m_utility.OutputMessage("ferry!\"");
	}
	else if (m_randomNum == 2) {
		m_utility.OutputMessage("Aunt Rebecca Sims tells you:");
		cout << endl;
		m_utility.OutputMessage("\"With the crowds of people");
		m_utility.OutputMessage("waiting to get on the ferry, we");
		m_utility.OutputMessage("could be stranded here for");
		m_utility.OutputMessage("days! Hope theres enough");
		m_utility.OutputMessage("graze for all those animals --");
		m_utility.OutputMessage("not many people carry feed!");
		m_utility.OutputMessage("I'd rather wait, though, than");
		m_utility.OutputMessage("cross in a rickety wagon boat!\"");
	}
	else {
		m_utility.DisplayError("ERROR: Invalid random number for K River Crossing.");
	}

}

void Dialogue::BBlueRiverCrossing() {

	if (m_randomNum == 0) {
		m_utility.OutputMessage("Big Louie, a trail driver,");
		m_utility.OutputMessage("tells you:");
		cout << endl;
		m_utility.OutputMessage("\"Be careful you don't push");
		m_utility.OutputMessage("those animals too hard! Keep");
		m_utility.OutputMessage("'em moving but set them a fair");
		m_utility.OutputMessage("pace. Can't keep driving 'em");
		m_utility.OutputMessage("so fast or you'll end up with");
		m_utility.OutputMessage("lame-footed animals. A lame ox");
		m_utility.OutputMessage("is about as good to you as a");
		m_utility.OutputMessage("dead one!\"");
	}
	else if (m_randomNum == 1) {
		m_utility.OutputMessage("A party leader heading east");
		m_utility.OutputMessage("tells you:");
		cout << endl;
		m_utility.OutputMessage("\"We've had enough! Pesky flies");
		m_utility.OutputMessage("all day and mosquitoes all");
		m_utility.OutputMessage("night! It's either baking sun");
		m_utility.OutputMessage("or oceans of mud -- and");
		m_utility.OutputMessage("sometimes both. Worry over");
		m_utility.OutputMessage("Indians attacking -- haven't");
		m_utility.OutputMessage("seen any yet, but still a");
		m_utility.OutputMessage("worry.\"");
	}
	else if (m_randomNum == 2) {
		m_utility.OutputMessage("A lady, Marnie Stewart, tells");
		m_utility.OutputMessage("you:");
		cout << endl;
		m_utility.OutputMessage("\"This prairie is mighty pretty");
		m_utility.OutputMessage("with all the wild flowers and");
		m_utility.OutputMessage("tall grasses. But there's too");
		m_utility.OutputMessage("much of it! I miss not having");
		m_utility.OutputMessage("a town nearby. I wonder how");
		m_utility.OutputMessage("many days until I see a town --");
		m_utility.OutputMessage("a town with real shops, a");
		m_utility.OutputMessage("church, people...\"");
	}
	else {
		m_utility.DisplayError("ERROR: Invalid random number for Big Blue River Crossing.");
	}
}

void Dialogue::FortKearney() {

	if (m_randomNum == 0) {
		m_utility.OutputMessage("A Fort Kearney scout tells you:");
		cout << endl;
		m_utility.OutputMessage("\"The game is still plentiful");
		m_utility.OutputMessage("along here, but gettin' harder");
		m_utility.OutputMessage("to find. With so many");
		m_utility.OutputMessage("overlanders, I don't expect it");
		m_utility.OutputMessage("to last more'n a few years.");
		m_utility.OutputMessage("Folks shoot the game for sport,");
		m_utility.OutputMessage("take a small piece, and let the");
		m_utility.OutputMessage("rest rot in the sun.\"");
	}
	else if (m_randomNum == 1) {
		m_utility.OutputMessage("A fort soldier tells you:");
		cout << endl;
		m_utility.OutputMessage("\"The trails from the jumping");
		m_utility.OutputMessage("off places -- Independence, St.");
		m_utility.OutputMessage("Joseph, Council Bluffs -- come");
		m_utility.OutputMessage("together at Fort Kearney. This");
		m_utility.OutputMessage("new fort was built by the U.S.");
		m_utility.OutputMessage("Army to protect those bound for");
		m_utility.OutputMessage("California and Oregon.\"");
	}
	else if (m_randomNum == 2) {
		m_utility.OutputMessage("Big Louie tells you:");
		cout << endl;
		m_utility.OutputMessage("\"The Platte River valley forms");
		m_utility.OutputMessage("a natural roadway from Fort");
		m_utility.OutputMessage("Kearney to Fort Laramie.");
		m_utility.OutputMessage("Travelers bound for California,");
		m_utility.OutputMessage("Utah, and Oregon all take this");
		m_utility.OutputMessage("road. Could be the easiest");
		m_utility.OutputMessage("stretch of the whole trip.");
		m_utility.OutputMessage("Should see Antelope and plenty");
		m_utility.OutputMessage("of buffalo.\"");
	}
	else {
		m_utility.DisplayError("ERROR: Invalid random number, Fort Kearney");
	}
}

void Dialogue::ChimneyRock() {

	if (m_randomNum == 0) {
		m_utility.OutputMessage("Aunt Rebecce Sims tells you:");
		cout << endl;
		m_utility.OutputMessage("\"I hear terrible stories about");
		m_utility.OutputMessage("wagon parties running out of");
		m_utility.OutputMessage("food before Oregon -- the whole");
		m_utility.OutputMessage("party starving to death. We");
		m_utility.OutputMessage("must check our supplies often;");
		m_utility.OutputMessage("we might not get there as soon");
		m_utility.OutputMessage("as we think. Always plan for");
		m_utility.OutputMessage("the worst, I say.\"");
	}
	else if (m_randomNum == 1) {
		m_utility.OutputMessage("Celinda Hines tells you:");
		cout << endl;
		m_utility.OutputMessage("\"Chimney Rock by moonlight is");
		m_utility.OutputMessage("awfully sublime. Many Indians");
		m_utility.OutputMessage("came to our wagon with fish to");
		m_utility.OutputMessage("exchange for clothing. We");
		m_utility.OutputMessage("bought a number. They");
		m_utility.OutputMessage("understand 'swap' and 'no");
		m_utility.OutputMessage("swap.' Seem most anxious to");
		m_utility.OutputMessage("get shirts and socks.\"");
	}
	else if (m_randomNum == 2) {
		m_utility.OutputMessage("Alonzo Delano tells you:");
		cout << endl;
		m_utility.OutputMessage("\"About noon yesterday we came");
		m_utility.OutputMessage("in sight of Chimney Rock");
		m_utility.OutputMessage("looming up in the distance like");
		m_utility.OutputMessage("the lofty tower of some town.");
		m_utility.OutputMessage("We did not tire gazing on it.");
		m_utility.OutputMessage("It was about 20 miles from us,");
		m_utility.OutputMessage("and stayed in sight 'til we");
		m_utility.OutputMessage("reached it today.\"");
	}
	else {
		m_utility.DisplayError("ERROR: Invalid random number, Chimney Rock");
	}
}

void Dialogue::FortLaramie() {

	if (m_randomNum == 0) {
		m_utility.OutputMessage("A Sioux brave tells you:");
		cout << endl;
		m_utility.OutputMessage("\"The Pawnee are the mortal");
		m_utility.OutputMessage("enemies of the Sioux. I would");
		m_utility.OutputMessage("not hesitate to kill any Pawnee");
		m_utility.OutputMessage("I met. But I have never killed");
		m_utility.OutputMessage("a white man. All I ask from");
		m_utility.OutputMessage("the white man is to leave me");
		m_utility.OutputMessage("alone, and to leave my buffalo");
		m_utility.OutputMessage("alone.\"");
	}
	else if (m_randomNum == 1) {
		m_utility.OutputMessage("A woman traveler tells you:");
		cout << endl;
		m_utility.OutputMessage("\"Be warned, stranger. Don't");
		m_utility.OutputMessage("dig a water hole! Drink only");
		m_utility.OutputMessage("river water. Salty as the");
		m_utility.OutputMessage("Platte River is -- it's better");
		m_utility.OutputMessage("than the cholera. We buried my");
		m_utility.OutputMessage("husband last week. Could use");
		m_utility.OutputMessage("some help with this harness, if");
		m_utility.OutputMessage("you can spare the time.\"");
	}
	else if (m_randomNum == 2) {
		m_utility.OutputMessage("A mountain man tells you:");
		cout << endl;
		m_utility.OutputMessage("\"These greenhorns heading");
		m_utility.OutputMessage("across the Rockies know nothing");
		m_utility.OutputMessage("about surviving in the");
		m_utility.OutputMessage("mountains. It gets awful cold");
		m_utility.OutputMessage("up there, even in summer. Many");
		m_utility.OutputMessage("a traveler crossing the");
		m_utility.OutputMessage("mountains get too late in the year");
		m_utility.OutputMessage("has gotten snowbound and died!\"");
	}
	else {
		m_utility.DisplayError("ERROR: Invalid random number, Fort Laramie");
	}
}

void Dialogue::IndependenceRock() {

	if (m_randomNum == 0) {
		m_utility.OutputMessage("A young boy tells you:");
		cout << endl;
		m_utility.OutputMessage("\"I carved my name way up the");
		m_utility.OutputMessage("side of Independence Rock, near");
		m_utility.OutputMessage("the top. There are hundreds of");
		m_utility.OutputMessage("names up there! The oldest");
		m_utility.OutputMessage("ones were carved by mountain");
		m_utility.OutputMessage("men and fur trappers -- famous");
		m_utility.OutputMessage("names like Fremont, Bonneville,");
		m_utility.OutputMessage("and DeSmet!\"");
	}
	else if (m_randomNum == 1) {
		m_utility.OutputMessage("Aunt Rebecca Sims tells you:");
		cout << endl;
		m_utility.OutputMessage("\"No butter or cheese or fresh");
		m_utility.OutputMessage("fruit since Fort Laramie!");
		m_utility.OutputMessage("Bless me, but I'd rather have");
		m_utility.OutputMessage("my larder full of food back");
		m_utility.OutputMessage("East than have our names carved");
		m_utility.OutputMessage("on that rock! Well, tis a");
		m_utility.OutputMessage("sight more cheery than all the");
		m_utility.OutputMessage("graves we passed.\"");
	}
	else if (m_randomNum == 2) {
		m_utility.OutputMessage("Big Louie tells you:");
		cout << endl;
		m_utility.OutputMessage("\"Goodbye Platte River! Goodbye");
		m_utility.OutputMessage("sand hills and white buffalo");
		m_utility.OutputMessage("skulls! Now we climb the");
		m_utility.OutputMessage("Sweetwater valley to cross the");
		m_utility.OutputMessage("Continental Divide at South");
		m_utility.OutputMessage("Pass. Once across the Rockies,");
		m_utility.OutputMessage("we'll make a steep descent into");
		m_utility.OutputMessage("the Green River valley.\"");
	}
	else {
		m_utility.DisplayError("ERROR: Invalid random number, Independence Rock");
	}
}

void Dialogue::SouthPass() {

	if (m_randomNum == 0) {
		m_utility.OutputMessage("An Arapaho Indian tells you:");
		cout << endl;
		m_utility.OutputMessage("\"When the white man first");
		m_utility.OutputMessage("crossed our lands their wagons");
		m_utility.OutputMessage("were few. Now they crowd the");
		m_utility.OutputMessage("trail in great numbers. The");
		m_utility.OutputMessage("land is overgrazed with their");
		m_utility.OutputMessage("many animals. Do any white men");
		m_utility.OutputMessage("still live in the East? My");
		m_utility.OutputMessage("people talk of moving.\"");
	}
	else if (m_randomNum == 1) {
		m_utility.OutputMessage("A young girl tells you:");
		cout << endl;
		m_utility.OutputMessage("\"My father is very sick and we");
		m_utility.OutputMessage("are resting here until he gets");
		m_utility.OutputMessage("better. We have been pushing");
		m_utility.OutputMessage("too hard and our health has");
		m_utility.OutputMessage("suffered. When my father is");
		m_utility.OutputMessage("able to travel again, we will");
		m_utility.OutputMessage("go at a slower pace.\"");
	}
	else if (m_randomNum == 2) {
		m_utility.OutputMessage("A mormon traveller tells you:");
		cout << endl;
		m_utility.OutputMessage("\"My family and I travel with 40");
		m_utility.OutputMessage("other families to the valley of");
		m_utility.OutputMessage("the Great Salt Lake to seek");
		m_utility.OutputMessage("religous freedom. Back east,");
		m_utility.OutputMessage("Mormons are persecuted. In");
		m_utility.OutputMessage("Utah, we'll join together to");
		m_utility.OutputMessage("build a new community, changing");
		m_utility.OutputMessage("desert into farm land.\"");
	}
	else {
		m_utility.DisplayError("ERROR: Invalid random number, South Pass");
	}
}

void Dialogue::FortBridger() {

	if (m_randomNum == 0) {
		m_utility.OutputMessage("A tired-looking woman tells");
		m_utility.OutputMessage("you:");
		cout << endl;
		m_utility.OutputMessage("\"One child drowned in a swollen");
		m_utility.OutputMessage("creek east of Fort Laramie. My");
		m_utility.OutputMessage("husband died of typhoid near");
		m_utility.OutputMessage("Independence Rock. Now I");
		m_utility.OutputMessage("travel alone with my five");
		m_utility.OutputMessage("children. The eldest, Caleb, is");
		m_utility.OutputMessage("eleven. I fear he'll be a man");
		m_utility.OutputMessage("before we reach Oregon.\"");
	}
	else if (m_randomNum == 1) {
		m_utility.OutputMessage("A trader tells you:");
		cout << endl;
		m_utility.OutputMessage("\"This fort was build by Jim");
		m_utility.OutputMessage("Bridger. Jim was a mountain");
		m_utility.OutputMessage("man before he put in this");
		m_utility.OutputMessage("blacksmith shop and small store");
		m_utility.OutputMessage("to supply the overlanders.");
		m_utility.OutputMessage("Does a big trade in horses, Jim");
		m_utility.OutputMessage("and his partner, Vasquez.\"");
	}
	else if (m_randomNum == 2) {
		m_utility.OutputMessage("Aunt Rebecca tells you:");
		cout << endl;
		m_utility.OutputMessage("\"We should've taken the");
		m_utility.OutputMessage("Sublette Cutoff! Not enough at");
		m_utility.OutputMessage("this fort worth the time it");
		m_utility.OutputMessage("took to get here. And the");
		m_utility.OutputMessage("outrageous prices! Food's not");
		m_utility.OutputMessage("fit to eat, much less pay for.");
		m_utility.OutputMessage("Some folks'd sell the clothes");
		m_utility.OutputMessage("off our backsif we'd let");
		m_utility.OutputMessage("them!\"");
	}
	else {
		m_utility.DisplayError("ERROR: Invalid random number, Fort Bridger");
	}
}

void Dialogue::GreenRiver() {

	if (m_randomNum == 0) {
		m_utility.OutputMessage("A young boy tells you:");
		cout << endl;
		m_utility.OutputMessage("\"My family didn't buy enough");
		m_utility.OutputMessage("food in Independence. We have");
		m_utility.OutputMessage("eating very small rations");
		m_utility.OutputMessage("since Fort Laramie. Because of");
		m_utility.OutputMessage("that our health is poor. My");
		m_utility.OutputMessage("sister has mountain fever, so");
		m_utility.OutputMessage("were stopped here for a");
		m_utility.OutputMessage("while.\"");
	}
	else if (m_randomNum == 1) {
		m_utility.OutputMessage("A Shoshoni Indian tells you:");
		cout << endl;
		m_utility.OutputMessage("\"When wagons first started");
		m_utility.OutputMessage("coming through here, we did not");
		m_utility.OutputMessage("mind. We even found it good to");
		m_utility.OutputMessage("trade game and fish with the");
		m_utility.OutputMessage("travelers and help them cross");
		m_utility.OutputMessage("the rivers. Now there are too");
		m_utility.OutputMessage("many white men and too little");
		m_utility.OutputMessage("land for grazing.\"");
	}
	else if (m_randomNum == 2) {
		m_utility.OutputMessage("Big Louie tells you:");
		cout << endl;
		m_utility.OutputMessage("\"Five dollars to ferry us over");
		m_utility.OutputMessage("the Green River? Those");
		m_utility.OutputMessage("ferrymen'll make a hundred");
		m_utility.OutputMessage("dollars before breakfast!");
		m_utility.OutputMessage("We'll keep down river until we");
		m_utility.OutputMessage("find a place to ford our wagon");
		m_utility.OutputMessage("and animals. What little money");
		m_utility.OutputMessage("we have left, we'll keep!\"");
	}
	else {
		m_utility.DisplayError("ERROR: Invalid random number, Green River");
	}
}

void Dialogue::SodaSprings() {

	if (m_randomNum == 0) {
		m_utility.OutputMessage("A young boy tells you:");
		cout << endl;
		m_utility.OutputMessage("\"My job every day is to find");
		m_utility.OutputMessage("wood for the cook fire.");
		m_utility.OutputMessage("sometimes it's very hard to");
		m_utility.OutputMessage("find enough, so I store extra");
		m_utility.OutputMessage("pieces in a box under the");
		m_utility.OutputMessage("wagon. On the prairie I");
		m_utility.OutputMessage("gathered buffalo chips to burn");
		m_utility.OutputMessage("when there wasn't any wood.\"");
	}
	else if (m_randomNum == 1) {
		m_utility.OutputMessage("Miles Hendrick tells you:");
		cout << endl;
		m_utility.OutputMessage("\"I've heard it said that there");
		m_utility.OutputMessage("are many cutoffs to take to");
		m_utility.OutputMessage("shorten the journey -- that by");
		m_utility.OutputMessage("taking all the shortcuts, you");
		m_utility.OutputMessage("can save many days on the");
		m_utility.OutputMessage("trail. Any why not? Saving");
		m_utility.OutputMessage("time and provisions is worth");
		m_utility.OutputMessage("the risk!\"");
	}
	else if (m_randomNum == 2) {
		m_utility.OutputMessage("Celinda Hines tells you:");
		cout << endl;
		m_utility.OutputMessage("\"My, the Soda Springs are so");
		m_utility.OutputMessage("pretty! Seem to spout at");
		m_utility.OutputMessage("regular intervals. Felt good");
		m_utility.OutputMessage("to just rest and not be jostled");
		m_utility.OutputMessage("in the wagon all day. When I");
		m_utility.OutputMessage("get to Oregon. I'll have a soft");
		m_utility.OutputMessage("feather bed and never sleep in");
		m_utility.OutputMessage("a wagon again!\"");
	}
	else {
		m_utility.DisplayError("ERROR: Invalid random number, Soda Springs");
	}
}

void Dialogue::FortHall() {

	if (m_randomNum == 0) {
		m_utility.OutputMessage("A fellow traveler tells you:");
		cout << endl;
		m_utility.OutputMessage("\"Fort Hall is a busy fort! The");
		m_utility.OutputMessage("wide stretches of meadow grass");
		m_utility.OutputMessage("here are just what our tired");
		m_utility.OutputMessage("animals need. As for me, I'll");
		m_utility.OutputMessage("fix up the wagon leaks.");
		m_utility.OutputMessage("Amanda's real anxious to wash");
		m_utility.OutputMessage("all the clothes and linens in");
		m_utility.OutputMessage("one of those clear streams.\"");
	}
	else if (m_randomNum == 1) {
		m_utility.OutputMessage("Miles Hendrick tells you:");
		cout << endl;
		m_utility.OutputMessage("\"Well, friend, this is where we");
		m_utility.OutputMessage("part. I'm bound for California");
		m_utility.OutputMessage("with an imposing desert to");
		m_utility.OutputMessage("cross. And you -- you've got");
		m_utility.OutputMessage("the Snake River to cross, which");
		m_utility.OutputMessage("I hear is no picnic! Write us,");
		m_utility.OutputMessage("you or the Missus, just as soon");
		m_utility.OutputMessage("as you reach Oregon!\"");
	}
	else if (m_randomNum == 2) {
		m_utility.OutputMessage("Aunt Rebecca tells you:");
		cout << endl;
		m_utility.OutputMessage("\"Hear there's mountain sheep");
		m_utility.OutputMessage("around here. Enough water too,");
		m_utility.OutputMessage("but hardly a stick of wood.");
		m_utility.OutputMessage("Thank heaven for Fort Hall!");
		m_utility.OutputMessage("But I'm real sorry to be saying");
		m_utility.OutputMessage("goodbye to cousin Miles and all");
		m_utility.OutputMessage("the folks heading for");
		m_utility.OutputMessage("California.\"");
	}
	else {
		m_utility.DisplayError("ERROR: Invalid random number, Fort Hall");
	}
}

void Dialogue::SnakeRiver() {

	if (m_randomNum == 0) {
		m_utility.OutputMessage("An overlander tells you:");
		cout << endl;
		m_utility.OutputMessage("\"Down there between those steep");
		m_utility.OutputMessage("lava gorges, twisting and");
		m_utility.OutputMessage("writhing, is the Snake River.");
		m_utility.OutputMessage("So much water -- and so hard to");
		m_utility.OutputMessage("get to! We've got many miles");
		m_utility.OutputMessage("of desert before Oregon, so be");
		m_utility.OutputMessage("sure to fill your water kegs at");
		m_utility.OutputMessage("the crossing!\"");
	}
	else if (m_randomNum == 1) {
		m_utility.OutputMessage("Big Louie tells you:");
		cout << endl;
		m_utility.OutputMessage("\"See that wild river? That's");
		m_utility.OutputMessage("the Snake. Many a craft's been");
		m_utility.OutputMessage("swamped in her foaming rapids.");
		m_utility.OutputMessage("Her waters travel all the way");
		m_utility.OutputMessage("to Oregon! We'll be crossing");
		m_utility.OutputMessage("her soon, and then again after");
		m_utility.OutputMessage("Fort Boise. Take care at the");
		m_utility.OutputMessage("crossing!\"");
	}
	else if (m_randomNum == 2) {
		m_utility.OutputMessage("A frantic wife tells you:");
		cout << endl;
		m_utility.OutputMessage("\"It says right here in the");
		m_utility.OutputMessage("Shively guidebook: \"You must");
		m_utility.OutputMessage("hire an Indian to pilot you at");
		m_utility.OutputMessage("the crossings of the Snake");
		m_utility.OutputMessage("river, it being dangerous if");
		m_utility.OutputMessage("not perfectly understood.\" But");
		m_utility.OutputMessage("my husband insists on crossing");
		m_utility.OutputMessage("without a guide!\"");
	}
	else {
		m_utility.DisplayError("ERROR: Invalid random number, Snake River");
	}
}

void Dialogue::FortBoise() {

	if (m_randomNum == 0) {
		m_utility.OutputMessage("Aunt Rebecca tells you:");
		cout << endl;
		m_utility.OutputMessage("\"At every fort along the trail,");
		m_utility.OutputMessage("prices have been higher than at");
		m_utility.OutputMessage("the previous fort! This is");
		m_utility.OutputMessage("outrageous! They're taking");
		m_utility.OutputMessage("advantage of us! If I had the");
		m_utility.OutputMessage("chance to do it again, I'd buy.");
		m_utility.OutputMessage("more supplies in Independence.\"");
	}
	else if (m_randomNum == 1) {
		m_utility.OutputMessage("Jacob Hofsteader tells you:");
		cout << endl;
		m_utility.OutputMessage("\"Every night, even though I");
		m_utility.OutputMessage("ache from the day's toils, my");
		m_utility.OutputMessage("head is filled with dreams of");
		m_utility.OutputMessage("the rich farm land of the");
		m_utility.OutputMessage("Willamette Valley. I will");
		m_utility.OutputMessage("build myself a fine, handsome");
		m_utility.OutputMessage("homestead -- and I'm certain");
		m_utility.OutputMessage("I'll be rich within five");
		m_utility.OutputMessage("years.\"");
	}
	else if (m_randomNum == 2) {
		m_utility.OutputMessage("A trader with 6 mules tells");
		m_utility.OutputMessage("you:");
		cout << endl;
		m_utility.OutputMessage("\"You'll not get yer wagon over");
		m_utility.OutputMessage("them Blue Mountains, mister.");
		m_utility.OutputMessage("Leave it! Cross yer goods over");
		m_utility.OutputMessage("with pack animals. Get yerself");
		m_utility.OutputMessage("a couple of good mules. Pieces");
		m_utility.OutputMessage("of wagons litter the traill --");
		m_utility.OutputMessage("left by them folks who don't");
		m_utility.OutputMessage("heed good advice!\"");
	}
	else {
		m_utility.DisplayError("ERROR: Invalid random number, Fort Boise");
	}
}

void Dialogue::BlueMountains() {

	if (m_randomNum == 0) {
		m_utility.OutputMessage("Jacob Hofsteader tells you:");
		cout << endl;
		m_utility.OutputMessage("\"This valley of the Grande");
		m_utility.OutputMessage("Ronde is the most beautiful");
		m_utility.OutputMessage("sight I've seen in months.");
		m_utility.OutputMessage("Water and graze in abundance!");
		m_utility.OutputMessage("And if this valley is so fine,");
		m_utility.OutputMessage("the Willamette must be twice as");
		m_utility.OutputMessage("fine! We'll be sittin' pretty");
		m_utility.OutputMessage("in our new homestead!\"");
	}
	else if (m_randomNum == 1) {
		m_utility.OutputMessage("A tired overlander tells you:");
		cout << endl;
		m_utility.OutputMessage("\"Since crossing the Snake at");
		m_utility.OutputMessage("Fort Boise, it's been just");
		m_utility.OutputMessage("mountains and desert. Dust");
		m_utility.OutputMessage("deeper each day -- six inches");
		m_utility.OutputMessage("at times. No tracks, just");
		m_utility.OutputMessage("clouds of dust. Many cattle");
		m_utility.OutputMessage("choked on the dust after");
		m_utility.OutputMessage("swimming the river, then bled");
		m_utility.OutputMessage("and died.\"");
	}
	else if (m_randomNum == 2) {
		m_utility.OutputMessage("Marnie Stewart tells you:");
		cout << endl;
		m_utility.OutputMessage("\"We followed the edge of the");
		m_utility.OutputMessage("desert from Fort Boise to the");
		m_utility.OutputMessage("forbidding wall of the Blue");
		m_utility.OutputMessage("Mountains. The hills were");
		m_utility.OutputMessage("deadful steep! Looking both");
		m_utility.OutputMessage("wheels and coming down slow, we");
		m_utility.OutputMessage("got down safe. Poor animals!");
		m_utility.OutputMessage("No grass or water for days.\"");
	}
	else {
		m_utility.DisplayError("ERROR: Invalid random number, Grande Ronde Valley");
	}
}

void Dialogue::FortWallaWalla() {

	if (m_randomNum == 0) {
		m_utility.OutputMessage("A young mother tells you:");
		cout << endl;
		m_utility.OutputMessage("\"I've traveled in fear of");
		m_utility.OutputMessage("Indians since our journey");
		m_utility.OutputMessage("began. As of yet we've seen");
		m_utility.OutputMessage("few. Those we met helped us");
		m_utility.OutputMessage("cross rivers or sold us");
		m_utility.OutputMessage("vegetables. Still I fear.");
		m_utility.OutputMessage("I've read grave markers and");
		m_utility.OutputMessage("heard stories of killings in");
		m_utility.OutputMessage("these mountains.\"");
	}
	else if (m_randomNum == 1) {
		m_utility.OutputMessage("Amy Witherspoon tells you:");
		cout << endl;
		m_utility.OutputMessage("\"My cousin Catherine was one of");
		m_utility.OutputMessage("six children orphaned and left");
		m_utility.OutputMessage("at Whitman's Mission. Lived");
		m_utility.OutputMessage("with them for three years --");
		m_utility.OutputMessage("until the massacre last");
		m_utility.OutputMessage("November. She has survived");
		m_utility.OutputMessage("snakebites, stampedes, falls,");
		m_utility.OutputMessage("fights -- not to mention a");
		m_utility.OutputMessage("massacre.\"");
	}
	else if (m_randomNum == 2) {
		m_utility.OutputMessage("A Cayuse Indian tells you:");
		cout << endl;
		m_utility.OutputMessage("\"You ask about the Whitman");
		m_utility.OutputMessage("massacre. I ask you why Doctor");
		m_utility.OutputMessage("Whitman's medicine did not cure");
		m_utility.OutputMessage("my people's children? Many");
		m_utility.OutputMessage("caught the measles from the");
		m_utility.OutputMessage("strangers. Why did the");
		m_utility.OutputMessage("medicine poison our children");
		m_utility.OutputMessage("and cure the children of white");
		m_utility.OutputMessage("people?\"");
	}
	else {
		m_utility.DisplayError("ERROR: Invalid random number, Fort Walla Walla");
	}
}

void Dialogue::TheDalles() {

	if (m_randomNum == 0) {
		m_utility.OutputMessage("A mountain man tells you:");
		cout << endl;
		m_utility.OutputMessage("\"These last hundred miles to");
		m_utility.OutputMessage("the Willamette Valley are the");
		m_utility.OutputMessage("roughest -- either rafting down");
		m_utility.OutputMessage("the swift and turbulent");
		m_utility.OutputMessage("Columbia River or driving your");
		m_utility.OutputMessage("wagon over the steep Cascade");
		m_utility.OutputMessage("Mountains. Hire an Indian");
		m_utility.OutputMessage("guide if you take the river.\"");
	}
	else if (m_randomNum == 1) {
		m_utility.OutputMessage("Amy Witherspoon tells you:");
		cout << endl;
		m_utility.OutputMessage("\"My cousin Lydia engaged");
		m_utility.OutputMessage("passage down the Columbia with");
		m_utility.OutputMessage("Indians -- a canoe with 17");
		m_utility.OutputMessage("people and luggage! The wind");
		m_utility.OutputMessage("blew so heavy they had to lay");
		m_utility.OutputMessage("by. Near dark, high waves came");
		m_utility.OutputMessage("up over their heads! Finally,");
		m_utility.OutputMessage("they made it to shore safely.\"");
	}
	else if (m_randomNum == 2) {
		m_utility.OutputMessage("A toll collector tells you:");
		cout << endl;
		m_utility.OutputMessage("\"I collect the tolls for the");
		m_utility.OutputMessage("Barlow Road -- a bargain at");
		m_utility.OutputMessage("twice the price! Until last");
		m_utility.OutputMessage("year the overlander had no");
		m_utility.OutputMessage("choice -- everyone floated the");
		m_utility.OutputMessage("Columbia. Now with Mr.");
		m_utility.OutputMessage("Barlow's new road, you can");
		m_utility.OutputMessage("drive your wagon right into");
		m_utility.OutputMessage("Oregon City!\"");
	}
	else {
		m_utility.DisplayError("ERROR: Invalid random number, The Dalles");
	}
}

void Dialogue::T_DepartingDialogue() {

	cout << endl << endl;
	m_utility.OutputMessage("Well then, you're ready");
	m_utility.OutputMessage("to start. Good luck!");
	m_utility.OutputMessage("You have a long and");
	m_utility.OutputMessage("difficult journey ahead");
	m_utility.OutputMessage("of you.");
	m_utility.Wait();
}