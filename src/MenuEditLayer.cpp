#include "MenuEditLayer.hpp"

using namespace cocos2d;

bool g_isEditingMode = false;

void MenuEditLayer::toggleEditing(CCLayer* currentLayer) {
    g_isEditingMode = !g_isEditingMode;
    
    if (g_isEditingMode) {
        geode::log::info("Editor enabled. Click and drag elements to move them.");
    } else {
        geode::log::info("Editor disabled. Layout saved.");
    }
}

void MenuEditLayer::handleDrag(CCNode* node, CCPoint touchLocation) {
    if (!g_isEditingMode || !node) return;

    if (node->getParent()) {
        CCPoint localPoint = node->getParent()->convertToNodeSpace(touchLocation);
        node->setPosition(localPoint);
        constrainToScreen(node);
    }
}

void MenuEditLayer::constrainToScreen(CCNode* node) {
    if (!node) return;

    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCPoint currentPos = node->getPosition();
    
    CCSize nodeSize = node->getContentSize();
    float scaleX = node->getScaleX();
    float scaleY = node->getScaleY();
    
    float halfWidth = (nodeSize.width * scaleX) / 2.0f;
    float halfHeight = (nodeSize.height * scaleY) / 2.0f;

    if (currentPos.x - halfWidth < 0) currentPos.x = halfWidth;
    if (currentPos.x + halfWidth > winSize.width) currentPos.x = winSize.width - halfWidth;

    if (currentPos.y - halfHeight < 0) currentPos.y = halfHeight;
    if (currentPos.y + halfHeight > winSize.height) currentPos.y = winSize.height - halfHeight;

    node->setPosition(currentPos);
}
