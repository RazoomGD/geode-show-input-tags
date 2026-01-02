#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/CCMenuItemToggler.hpp>
#include <Geode/modify/CCTextInputNode.hpp>

class $modify(CCMenuItemToggler) {
	void toggle(bool on) {

		CCMenuItemToggler::toggle(on);

		if (!getChildByID("tag_lbl")) {
			queueInMainThread([this](){
				if (getTag() != -1 && !getChildByID("tag_lbl")) {
					auto lbl = CCLabelBMFont::create(std::to_string(getTag()).data(), "chatFont.fnt");
					lbl->setColor(Mod::get()->getSettingValue<ccColor3B>("col-1"));
					lbl->setID("tag_lbl");
					lbl->setScale(0.7);
					addChildAtPosition(lbl, Anchor::Center);
				}
			});
		}
	}

};

class $modify(CCTextInputNode) {
	bool init(float width, float height, char const* placeholder, char const* textFont, int fontSize, char const* labelFont) {
		if (!CCTextInputNode::init(width, height, placeholder, textFont, fontSize, labelFont)) return false;
		
		if (!getChildByID("tag_lbl")) {
			queueInMainThread([this](){
				if (getTag() != -1 && !getChildByID("tag_lbl")) {
					auto lbl = CCLabelBMFont::create(std::to_string(getTag()).data(), "chatFont.fnt");
					lbl->setColor(Mod::get()->getSettingValue<ccColor3B>("col-2"));
					lbl->setID("tag_lbl");
					lbl->setScale(0.6);
					addChild(lbl);
					lbl->setPosition(lbl->getPosition() + ccp(0, 10));
				}
			});
		}

		return true;
	}

};