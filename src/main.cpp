#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "MenuEditLayer.hpp"

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto mainMenu = this->getChildByID("right-side-menu");
        if (!mainMenu) {
            mainMenu = this->getChildByID("main-menu");
        }

        if (mainMenu) {
            auto sprite = CCSprite::createWithSpriteFrameName("GJ_plusBtn_001.png");
            auto button = CCMenuItemSpriteExtra::create(
                sprite,
                this,
                menu_selector(MyMenuLayer::onCustomizeUI)
            );

            button->setID("ui-customer-btn");
            mainMenu->addChild(button);
            mainMenu->updateLayout();
        }

        return true;
    }

    void onCustomizeUI(CCObject* sender) {
        log::info("UI Customization mode activated!");
        MenuEditLayer::toggleEditing(this);
    }
};
