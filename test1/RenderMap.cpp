#include "stdafx.h"
#include "RenderMap.h"
#include "RenderComponent.h"
#include "Game.h"

using namespace std;

RenderMap::RenderMap() {

}

RenderMap::~RenderMap() {

}

RenderComponent* RenderMap::getRenderComponent(unsigned id) {
	return _renderMap.find(id)->second;
}

void RenderMap::addRenderComponent(unsigned id, sf::Sprite& sprite) {
	auto rc = new RenderComponent(id, sprite); 
	_renderMap.insert(pair<unsigned, RenderComponent*>(id, rc));
}

void RenderMap::drawAll() {
	for_each(begin(_renderMap), end(_renderMap), [&](pair<unsigned, RenderComponent*> i){
		i.second->draw(Game::GetWindow());
	});
}