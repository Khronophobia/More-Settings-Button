#include <Geode/Geode.hpp>
#include <Geode/modify/EditLevelLayer.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

using namespace geode::prelude;

class $modify(EditLevelLayer) {
	bool init(GJGameLevel* p0) {
		if (!EditLevelLayer::init(p0)) return false;

		auto optionsSprite = CCSprite::createWithSpriteFrameName("GJ_optionsBtn02_001.png");
		auto optionsButton = CCMenuItemSpriteExtra::create(optionsSprite, this, menu_selector(MenuLayer::onOptions));

		auto menu = this->getChildByID("back-menu");
		menu->addChild(optionsButton);
		menu->updateLayout();

		return true;
	}
};

class $modify(LevelInfoLayer) {
	bool init(GJGameLevel* p0, bool p1) {
		if (!LevelInfoLayer::init(p0, p1)) return false;

		auto optionsSprite = CCSprite::createWithSpriteFrameName("GJ_optionsBtn02_001.png");
		auto optionsButton = CCMenuItemSpriteExtra::create(optionsSprite, this, menu_selector(MenuLayer::onOptions));

		auto menu = this->getChildByID("back-menu");
		menu->addChild(optionsButton);
		menu->updateLayout();

		return true;
	}
};
