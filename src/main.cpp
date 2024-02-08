#include <Geode/Geode.hpp>
#include <Geode/modify/EditLevelLayer.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

using namespace geode::prelude;

class $modify(EditLevelLayer) {
	bool init(GJGameLevel* p0) {
		if (!EditLevelLayer::init(p0)) return false;

		auto settingsSprite = CCSprite::createWithSpriteFrameName("GJ_optionsBtn02_001.png");
		auto settingsButton = CCMenuItemSpriteExtra::create(settingsSprite, this, menu_selector(MenuLayer::onOptions));

		auto menu = this->getChildByID("back-menu");
		menu->addChild(settingsButton);
		menu->updateLayout();

		return true;
	}
};

class $modify(LevelInfoLayer) {
	bool init(GJGameLevel* p0, bool p1) {
		if (!LevelInfoLayer::init(p0, p1)) return false;

		auto settingsSprite = CCSprite::createWithSpriteFrameName("GJ_optionsBtn02_001.png");
		auto settingsButton = CCMenuItemSpriteExtra::create(settingsSprite, this, menu_selector(MenuLayer::onOptions));

		auto menu = this->getChildByID("back-menu");
		menu->addChild(settingsButton);
		menu->updateLayout();

		return true;
	}
};
