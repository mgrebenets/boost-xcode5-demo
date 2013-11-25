//
//  BDGameTest.m
//  boost-xcode5-demo
//
//  Created by Grebenets, Maksym on 11/25/13.
//  Copyright (c) 2013 i4nApps. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "Game.h"

#define UTF8_CSTR(_str_) [(_str_) cStringUsingEncoding:NSUTF8StringEncoding]

using std::string;

@interface BDGameTest : XCTestCase

@property (nonatomic, strong) NSString *save_path1;
@property (nonatomic, strong) NSString *save_path2;

@end

@implementation BDGameTest

- (NSURL *)applicationDocumentsDirectoryURL
{
    return [[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] lastObject];
}

- (NSString *)applicationDocumentsDirectoryPath {
    return self.applicationDocumentsDirectoryURL.filePathURL.path;
}


void saveGame(Game *game, const char *filename) {
    std::ofstream ofs(filename);
    boost::archive::xml_oarchive oa(ofs);
    oa << BOOST_SERIALIZATION_NVP(game);
    ofs.close();
}

Game *loadGame(const char *filename) {
    std::ifstream ifs(filename);
    boost::archive::xml_iarchive ia(ifs);
    Game *g = new Game();
    ia >> BOOST_SERIALIZATION_NVP(*g);
    ifs.close();
    return g;
}

bool compareGames(Game *game1, Game *game2) {
    return (*game1) == (*game2);
}

bool compareFiles(NSString *file1, NSString *file2) {
    return [[NSFileManager defaultManager] contentsEqualAtPath:file1 andPath:file2];
}
- (void)setUp
{
    [super setUp];
    // Put setup code here; it will be run once, before the first test case.



    NSString *path = [self applicationDocumentsDirectoryPath];
    self.save_path1 = [path stringByAppendingPathComponent:@"save_file1.xml"];
    self.save_path2 = [path stringByAppendingPathComponent:@"save_file2.xml"];

    NSLog(@"Save files dir: %@", path);

}

- (void)tearDown
{
    // Put teardown code here; it will be run once, after the last test case.
    [super tearDown];
}

- (void)testGameSerializationWithExternalMethods
{
    Game game;
    game.set_round(4);

    // save
    string save_file1 = string(UTF8_CSTR(self.save_path1));
    saveGame(&game, save_file1.c_str());

    // load
    Game *loadedGame = loadGame(save_file1.c_str());

    // compare games (parts of them)
    XCTAssert(compareGames(&game, loadedGame), @"Games must be same!");

    // save again
    string save_file2 = string(UTF8_CSTR(self.save_path2));
    saveGame(loadedGame, save_file2.c_str());

    // compare files
    XCTAssert(compareFiles(self.save_path1, self.save_path2), @"Files must be same!");
}

- (void)testGameSerializationWithClassMethods
{
    Game game;
    game.set_round(5);

    // save
    string save_file1 = string(UTF8_CSTR(self.save_path1));
    game.SaveGame(save_file1.c_str());

    // load
    Game *loadedGame = Game::LoadGame(save_file1.c_str());

    // compare games (parts of them)
    XCTAssert(compareGames(&game, loadedGame), @"Games must be same!");

    // save again
    string save_file2 = string(UTF8_CSTR(self.save_path2));
    loadedGame->SaveGame(save_file2.c_str());

    // compare files
    XCTAssert(compareFiles(self.save_path1, self.save_path2), @"Files must be same!");
}


@end
