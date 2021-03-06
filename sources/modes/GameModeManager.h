/*
    This file is part of Heriswap.

    @author Soupe au Caillou - Jordane Pelloux-Prayer
    @author Soupe au Caillou - Gautier Pelloux-Prayer
    @author Soupe au Caillou - Pierre-Eric Pelloux-Prayer

    Heriswap is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, version 3.

    Heriswap is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Heriswap.  If not, see <http://www.gnu.org/licenses/>.
*/


#pragma once

#include <base/EntityManager.h>

#include "api/StorageAPI.h"
#include "HeriswapGame.h"
#include "InGameUiHelper.h"
#include "SuccessManager.h"

enum GameMode {
	Normal = 0,
	TilesAttack,
	Go100Seconds
};

class GameModeManager {
	public:
		struct BranchLeaf {
			Entity e;
			unsigned int type;
		};
		struct Render {
			glm::vec2 v;
			float rot;
		};

		GameModeManager(HeriswapGame* game, SuccessManager* successMgr, StorageAPI* sAPI);

		virtual ~GameModeManager() {}

		// to be called once: create long standing entities
		virtual void Setup();
		// to be called at the beginning of each game: setup entites, scoring, etc..
		virtual void Enter();
		// to be called during the game (only in UserInput GameState) - return game completion percentage
		virtual void GameUpdate(float dt, Scene::Enum state) = 0;
		// to be called during the game (only in UserInput GameState) - return game completion percentage
		virtual float GameProgressPercent() = 0;
		// to be called once per frame during game
		virtual void UiUpdate(float dt) = 0;
		// to be called after game-over occured
		virtual void Exit();
		// to be called to toggle pause mode display
		virtual void TogglePauseDisplay(bool paused);

		#if SAC_DEBUG
		void toggleDebugDisplay();
		bool _debug;
		Entity debugEntities[16];
		#endif
		int countBranchLeavesOfType(int t) const;


		// scoring interface
		virtual void WillScore(int nb, int type, std::vector<BranchLeaf>& out) = 0;
		virtual void ScoreCalc(int nb, unsigned int type) = 0;
		virtual GameMode GetMode() = 0;
		virtual bool LevelUp() = 0;

        // state save/restore
        virtual int saveInternalState(uint8_t** out);
        virtual const uint8_t* restoreInternalState(const uint8_t* in, int size);
		void generateLeaves(int* nb, int type);

		float position(float t);

        void showGameDecor(bool onlyBg);
	protected:
		void LoadHerissonTexture(int type);
		void updateHerisson(float dt, float obj, float herissonSpeed);
		void deleteLeaves(unsigned int type, int nb);
		Entity createAndAddLeave(int type, const glm::vec2& position, float rotation);

	public:
		// game params
		float time;
		unsigned int points, bonus, limit;
        Entity sky;
		Entity herisson;
		//feuilles de l'arbre
		std::vector<BranchLeaf> branchLeaves;

		// display elements
		InGameUiHelper uiHelper;
	protected:
		Entity branch;
		Entity decor1er, decor2nd;
		std::vector<glm::vec2> pts;

		SuccessManager* successMgr;

		StorageAPI* storageAPI;
	private:
		std::vector<Render> posBranch;
		void fillVec();
};
