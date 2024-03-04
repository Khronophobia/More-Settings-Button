#include <Geode/Geode.hpp>
#include <Geode/modify/EditLevelLayer.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

using namespace geode::prelude;

class $modify(EditLevelLayer) {
	bool init(GJGameLevel* p0) {
		if (!EditLevelLayer::init(p0)) return false;

		auto optionsSprite = CCSprite::createWithSpriteFrameName("GJ_optionsBtn02_001.png");
		auto optionsButton = CCMenuItemSpriteExtra::create(optionsSprite, this, menu_selector(MenuLayer::onOptions));
		optionsButton->setID("game-settings-button"_spr);

		auto menu = this->getChildByID("back-menu");
		menu->addChild(optionsButton);
		menu->updateLayout();

		return true;
	}
};

class $modify(LevelInfoLayer) {
	bool init(GJGameLevel* p0, bool p1) {
		if (!LevelInfoLayer::init(p0, p1)) return false;

		CCNode* menu;
		CCMenuItemSpriteExtra* optionsButton;
		if (Mod::get()->getSettingValue<bool>("use-settings-rope")) {
			auto optionsSprite = CCSprite::create("settingsRope_001.png"_spr);
			optionsButton = CCMenuItemSpriteExtra::create(optionsSprite, this, menu_selector(MenuLayer::onOptions));
			optionsButton->setSizeMult(1);
			optionsButton->useAnimationType(MenuAnimationType::Move);
			optionsButton->m_destPosition = CCPoint{0, -8.f};
			optionsButton->setPositionX(-40.f);

			menu = this->getChildByID("garage-menu");
			menu->addChild(optionsButton);
		} else {
			auto optionsSprite = CCSprite::createWithSpriteFrameName("GJ_optionsBtn02_001.png");
			optionsButton = CCMenuItemSpriteExtra::create(optionsSprite, this, menu_selector(MenuLayer::onOptions));

			menu = this->getChildByID("back-menu");
			auto backBtn = menu->getChildByID("back-button");
			menu->insertAfter(optionsButton, backBtn);
		}
		menu->updateLayout();
		optionsButton->setID("game-settings-button"_spr);

		return true;
	}
};
