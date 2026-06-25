#include <Geode/Geode.hpp>

class MenuEditLayer {
public:
    static void toggleEditing(cocos2d::CCLayer* currentLayer);
    static void handleDrag(cocos2d::CCNode* node, cocos2d::CCPoint touchLocation);
    static void constrainToScreen(cocos2d::CCNode* node);
};
