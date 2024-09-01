/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#include <Geode/utils/web.hpp>

#include <Geode/modify/MenuLayer.hpp>
#include <Geode/binding/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {

	bool init() {

		if (!MenuLayer::init()) {
			return false;
		}

		auto myButton = CCMenuItemSpriteExtra::create(
			cocos2d::CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png"),
			this,
		
			menu_selector(MyMenuLayer::onMyButton)
		);

		auto menu = this->getChildByID("more-games-menu");
		menu->addChild(myButton);

		myButton->setID("my-button"_spr);
		/** add image */
		auto MyImage = CCMenuItemSpriteExtra::create(
			cocos2d::CCSprite::createWithSpriteFrameName("LoadingBG.png"_spr),
			this,

			menu_selector(MyMenuLayer::onMyImage)
		);
		menu->addChild(MyImage);

		myButton->setID("my-image");

		menu->updateLayout();

		return true;
	}

	void onMyImage(CCObject*) {
		FLAlertLayer::create("Test", "This is myImage", "Close")->show();
	}

	void onMyButton(CCObject*) {
		FLAlertLayer::create("Info", "This version of Geometry Dash is very gangster", "Close")->show();
	}

		
	};