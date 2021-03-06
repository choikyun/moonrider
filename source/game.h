/**
 * @file game.h
 * @brief ゲーム本体のヘッダ
 * @date  2019/05/28
 * @author Choi Gyun
 */

/***************************************************
 * Moon Rider
 * ver 1.0.0
 * 2019.04.19
 * Choi Gyun
 *****************************************************/

#ifndef _game_h_
#define _game_h_

#include "bg.h"
#include <gba.h>

#ifdef GLOBAL_VALUE_DEFINE
#define GLOBAL
#define GLOBAL_VAL(v) = (v)
#else
#define GLOBAL extern
#define GLOBAL_VAL(v)
#endif

///////////////////////////////////////////////////////////////////// 各種定義

/***************************************************
 * 汎用的な定義
 ***************************************************/

/**
 * @brief 固定小数点部分 16bit
 */
#define FIX (16)

/**
 * @brief 数字　幅
 */
#define NUM_W (8)

/**
 * @brief 数字　高さ
 */
#define NUM_H (8)

/**
 * @brief 数字の実際の幅
 *
 * MODE4では16bit単位で書き込むため
 */
#define REAL_NUM_W (NUM_W / 2)

/**
 * @brief キー入力　長さ
 */
#define DEF_KEY_DELAY (1)

/**
 * @brief キー入力 リピート
 */
#define DEF_KEY_REPEAT (1)

/**
 * @brief メッセージ表示ウェイト
 */
#define MES_WAIT (20)

/**
 * @brief メッセージ点滅カウント
 */
#define MES_COUNT (10)

/**
 * @brief 一般オブジェクト　幅
 */
#define OBJ_W (32)

/**
 * @brief 一般オブジェクト　高さ
 */
#define OBJ_H (32)

/**
 * @brief 画面の中心
 */
#define SCREEN_CENTER (SCREEN_WIDTH / 2)

/***************************************************
 * ゲーム個別
 ***************************************************/
/*
 * ゲームバランスに関連するパラメータ
 */

/**
 * @brief ブロックの出現間隔
 */
#define BLOCK_INTERVAL (19)

/**
 * @brief ブロックの同時出現数
 */
#define APPER_MAX_BLOCKS (1)

/**
 * ブロック 速度
 */
//#define BLOCK_SPEED (-4096 * 25)

/**
 * @brief 次のレベルまで（フレーム）
 */
#define NEXT_LEVEL (30 * 60)

/***************************************************
 * モード
 ***************************************************/

/**
 * @brief ゲームモード数
 */
#define MAX_MODE (2)

/**
 * @brief モード選択矢印 X座標
 */
#define MODE_ARROW_X (84)

/**
 * @brief モード選択矢印 X座標 2
 */
#define MODE_ARROW_X2 (38)

/**
 * @brief モード選択矢印 Y座標
 */
#define MODE_ARROW_Y (122)

/***************************************************
 * トロフィー
 ***************************************************/

/**
 * @brief トロフィーの数
 */
#define MAX_TROPHY (6)

/**
 * @brief アンロックメッセージ　X座標
 */
#define UNLOCK_MES_X (90)

/**
 * @brief アンロックメッセージ　Y座標
 */
#define UNLOCK_MES_Y (76)

/**
 * @brief アンロックメッセージ　インターバル
 */
#define UNLOCK_MES_INTERVAL (6)

/**
 * @brief アンロックメッセージ　幅
 */
#define UNLOCK_MES_W (48)

/**
 * @brief アンロックメッセージ　高さ
 */
#define UNLOCK_MES_H (7)

/**
 * @brief トロフィーマーク　X座標
 */
#define TROPHY_X (192)

/**
 * @brief トロフィーマーク　Y座標
 */
#define TROPHY_Y (1)

/**
 * @brief トロフィーマーク　幅
 */
#define TROPHY_W (8)

/**
 * @brief トロフィーマーク　高さ
 */
#define TROPHY_H (8)

/***************************************************
 * ステージ
 ***************************************************/

/**
 * @brief Z座標 最大値
 */
#define MAX_Z (300)

/**
 * @brief Z座標 最小値
 */
#define MIN_Z (20)

/**
 * @brief ステータス表示域の高さ
 */
#define STATUS_HEIGHT (32)

/**
 * @brief ステージY方向の余白
 */
#define STAGE_Y_BLANK (80 + 40)

/**
 * @brief 座標補正X
 * 
 * ステージの論理座標からデバイス座標へ変換
 */
#define FIX_STAGE_X (SCREEN_WIDTH / 2)

/**
 * @brief 座標補正Y
 * 
 * ステージの論理座標からデバイス座標へ変換
 */
#define FIX_STAGE_Y (16)

/**
 * @brief BG開始 Y座標
 */
#define BG_Y (26)

/**
 * @brief BGカラー 単色
 */
#define BG_COLOR (11) // 黒

/***************************************************
 * 自機 スプライト
 ***************************************************/

/**
 * @brief 自機 幅
 */
#define SHIP_W (31)

/**
 * @brief 自機 高さ
 */
#define SHIP_H (31)

/**
 * @brief 自機 X座標 中心
 */
#define SHIP_X (0)

/**
 * @brief 自機 Y座標 中心
 */
#define SHIP_Y (128)

/**
 * @brief 自機 Z座標
 */
#define SHIP_Z MIN_Z

/**
 * @brief 自機 移動X座標最小値
 */
#define SHIP_MOVE_MIN_X (-200)

/**
 * @brief 自機 移動X座標最大値
 */
#define SHIP_MOVE_MAX_X (200)

/**
 * @brief 自機 移動Y座標最小値
 */
#define SHIP_MOVE_MIN_Y (STAGE_Y_BLANK)

/**
 * @brief 自機 移動Y座標最大値
 */
#define SHIP_MOVE_MAX_Y (SCREEN_HEIGHT - SHIP_H / 2)

/**
 * @brief 自機 加速度
 */
#define SHIP_SPEED (4096 * 2)

/**
 * @brief 自機自然減速
 */
#define SHIP_FRIC (0.01)

/**
 * @brief 自機最大加速度
 */
#define MAX_SHIP_ACC (3 << FIX)

/**
 * @brief 自機警告点滅インターバル
 */
#define SHIP_CAUTION_INTERVAL (3)

/***************************************************
 * エネルギー
 ***************************************************/

/**
 * @brief エネルギー用の小数点
 */
#define E_FIX (8)

/**
 * @brief エネルギー最大値
 */
#define MAX_ENERGY (30)

/**
 *  @brief エネルギー 余剰分
 */
#define MAX_ENERGY_BLANK (1)

/**
 * @brief エネルギーバー表示 X座標
 */
#define ENERGY_X (168)

/**
 * @brief エネルギーバー表示 Y座標
 */
#define ENERGY_Y (0)

/**
 * @brief エネルギーバーの幅
 */
#define ENERGY_W (2)

/**
 * @brief エネルギーバーの高さ
 */
#define ENERGY_H (8)

/**
 * @brief ダメージ
 */
#define DAMAGE_ENERGY (-12 << E_FIX)

/**
 * @brief 回復
 */
#define RECOVERY_ENERGY (6 << E_FIX)

/***************************************************
 * 逆噴射
 ***************************************************/

/**
 * @brief 使用エネルギー
 */
#define BOOTER_ENERGY (-10 << E_FIX)

/**
 * @brief 逆噴射の加速
 */
#define BOOSTER_ACC (2 << FIX)

/**
 * @brief 逆噴射時間
 */
#define BOOST_TIME (1 * 60)

/**
 * @brief 逆噴射 Y座標補正
 */
#define BOOSTER_FIXED_Y (-8)

/**
 * @brief 逆噴射アイコン X座標
 */
#define BOOSTER_ICON_X (232)

/**
 * @brief 逆噴射アイコン Y座標
 */
#define BOOSTER_ICON_Y (0)

/**
 * @brief 逆噴射アニメ インターバル
 */
#define BOOSTER_ICON_INTERVAL (3)

/**
 * @brief 逆噴射利用開始までの時間
 */
#define USE_BOOSTER_INTERVAL (20 * 60)

/**
 * @brief 逆噴射利用
 */
#define ALLOW_BOOSTER_ENERGY (MAX_ENERGY / 2)


/***************************************************
 * 振動アニメ
 ***************************************************/

/**
 * @brief 振動の振幅
 */
#define SHOCK_RANGE (4)

/**
 * @brief 振動の間隔
 */
#define SHOCK_INTERVAL (2)

/**
 * @brief 振動の長さ
 */
#define SHOCK_DURATION (SHOCK_INTERVAL * 6)

/***************************************************
 * 炎 スプライト
 ***************************************************/

/**
 * @brief 炎 幅
 */
#define FIRE_W (15)

/**
 * @brief 炎 高さ
 */
#define FIRE_H (15)

/**
 * @brief 炎 X座標 中心
 */
#define FIRE_X (0)

/**
 * @brief 炎 Y座標 中心
 */
#define FIRE_Y (6)

/**
 * @brief 炎 Y座標 中心 自機が上移動のとき
 */
#define FIRE_Y_UP (10)

/**
 * @brief 炎 Y座標 中心 自機が下移動のとき
 */
#define FIRE_Y_DOWN (4)

/**
 * @brief 炎 Y座標 中心 自機が上移動のとき
 */
#define FIRE_X_LEFT (4)

/**
 * @brief 炎 Y座標 中心 自機が下移動のとき
 */
#define FIRE_X_RIGHT (-4)

/**
 * @brief 炎 Y座標
 */
#define FIRE_Z MIN_Z

/**
 * @brief 炎 点滅間隔
 */
#define FIRE_INTERVAL (3)

/***************************************************
 * ブロック スプライト
 ***************************************************/

/**
 * @brief ブロック 幅
 */
#define BLOCK_W (40)
//#define BLOCK_W (80)

/**
 * @brief ブロック 高さ
 */
#define BLOCK_H (40)
//#define BLOCK_H (80)

/**
 * @brief スプライト幅
 */
#define BLOCK_SP_W (64)
//#define BLOCK_SP_W (128)

/**
 * @brief スプライト高さ
 */
#define BLOCK_SP_H (64)
//#define BLOCK_SP_H (128)

/**
 * @brief ブロック最大数
 */
#define MAX_BLOCKS (16)

/**
 * @brief dデフォルトの加速度
 */
#define DEF_BLOCK_ACC (-4096 * 1)

/**
 * @brief Z加速度最大値
 */
#define BLOCK_MAX_ACC (4) << FIX)

/**
 * @brief ブロック出現間隔 X方向
 */
#define BLOCK_X_STEP (40)

/**
 * @brief ブロック出現 Y方向
 */
#define BLOCK_Y_STEP (40)

/**
 * @brief X方向の出現数
 */
#define BLOCK_X_STEP_NUM (10 - 1)

/**
 * @brief X方向の余白 2キャラ分
 */
#define BLOCK_X_STEP_BLANK (BLOCK_X_STEP *2)

/**
 * @brief Y方向の出現数
 */
#define BLOCK_Y_STEP_NUM (0)

/**
 * @brief ブロック着地点の余白
 */
#define BLOCK_Y_TARGET_BLANK (SCREEN_HEIGHT - BLOCK_H * 2 - FIX_STAGE_Y)

/**
 * @brief ブロック着地点 Y座標
 */
#define BLOCK_Y_TARGET (SHIP_Y - 40)

/***************************************************
 * ガイド
 ***************************************************/

/**
 * @brief ガイド幅
 */
#define GUIDE_W (8)

/**
 * @brief ガイド高さ
 */
#define GUIDE_H (8)

/**
 * @brief ガイドY座標
 */
#define GUIDE_Y (SHIP_Y + 12)

/***************************************************
 * 水平線
 ***************************************************/

/**
 * @brief 水平線の最大数
 */
#define MAX_LINES (10)

/**
 * @brief 水平線 速度
 */
#define LINE_SPEED (-4096 * 25)

/**
 * @brief 水平線出現間隔 Z座標
 */
#define LINE_INTERVAL (MAX_Z / MAX_LINES)

/**
 * @brief 水平線 Z座標 デフォルト
 */
#define LINE_Z MAX_Z

/**
 * @brief 水平線 幅
 */
#define LINE_W (SCREEN_WIDTH)

/**
 * @brief 水平線 X座標
 */
#define LINE_X (-120)

/**
 * @brief 水平線の目標Y座標
 */
#define LINE_Y_TARGET (SCREEN_HEIGHT - FIX_STAGE_Y)

/**
 * @brief 水平線の色
 */
#define LINE_COLOR (38 | 38 << 8 | 38 << 16 | 38 << 24) // 赤

/***************************************************
 * 境界線
 ***************************************************/

/**
 * @brief 境界線 幅
 */
#define BOUNDARY_W (7)

/**
 * @brief 境界線 高さ
 */
#define BOUNDARY_H (32)

/**
 * @brief 境界線 Y座標
 */
#define BOUNDARY_Y (SHIP_Y - BOUNDARY_H / 2)

/***************************************************
 * アイコン
 ***************************************************/

/**
 * @brief リングアイコン Y座標
 */
#define ICON_RING_Y (-5)

/**
 * @brief リングアイコン ターゲット Y座標
 */
#define ICON_TARGET_Y (-20)

/**
 * @brief アイコン 表示時間
 */
#define ICON_LIFE (30)

/**
 * @brief アイコン 幅
 */
#define ICON_W (11)

/**
 * @brief アイコン 高さ
 */
#define ICON_H (11)

/**
 * @brief アイコン Y方向 加速度
 */
#define ICON_Y_ACC (-1 << FIX)

/***************************************************
 * フラッシュ
 ***************************************************/

/**
 * @brief フラッシュ　間隔
 */
#define FLASH_INTERVAL (4)

/**
 * @brief フラッシュ　色
 */
#define FLASH_COLOR (15)

/***************************************************
 *　スコア
 ***************************************************/

/**
 * @brief 通常のスコア フレーム毎に加算
 */
#define NORMAL_SCORE (10)

/**
 * @brief スコア表示桁
 */
#define SCORE_DIGIT (8)

/**
 * @brief スコア X座標
 */
#define SCORE_X (76)

/**
 * @brief スコア Y座標
 */
#define SCORE_Y LV_Y

/**
 * @brief ハイスコア X座標
 */
#define HISCORE_X (124)

/**
 * @brief ハイスコア Y座標
 */
#define HISCORE_Y (107)

/**
 * @brief ボーナス表示桁
 */
#define BONUS_DIGET (8)

/**
 * @brief ボーナス メッセージ X座標
 */
#define BONUS_MES_X (70)

/**
 * @brief ボーナス メッセージ Y座標
 */
#define BONUS_MES_Y (90)

/**
 * @brief ボーナス メッセージ 幅
 */
#define BONUS_MES_W (36)

/**
 * @brief ボーナス メッセージ 高さ
 */
#define BONUS_MES_H (8)

/**
 * @brief ボーナス X座標
 */
#define BONUS_X (110)

/**
 * @brief ボーナス Y座標
 */
#define BONUS_Y (BONUS_MES_Y)

/**
 * @brief リングボーナス単位
 */
#define RING_BONUS_UNIT (500)

/**
 * @brief ブロックボーナス 判定のしきい値
 */
#define BELOW_BLOCK_BONUS (50)

/**
 * @brief ブロックボーナス 
 */
#define BLOCK_BONUS (1000)

/**
 * @brief トータル メッセージ X座標
 */
#define TOTAL_MES_X (70)

/**
 * @brief トータル メッセージ Y座標
 */
#define TOTAL_MES_Y (100)

/**
 * @brief トータル メッセージ 幅
 */
#define TOTAL_MES_W (36)

/**
 * @brief トータル メッセージ 高さ
 */
#define TOTAL_MES_H (8)

/**
 * @brief トータル X座標
 */
#define TOTAL_X (110)

/**
 * @brief トータル Y座標
 */
#define TOTAL_Y (TOTAL_MES_Y)

/***************************************************
 *　リング
 ***************************************************/

/**
 * @brief リング数 桁
 */
#define RING_DIGIT (2)

/**
 * @brief リング数 X座標
 */
#define RING_X (152)

/**
 * @brief リング数　Y座標
 */
#define RING_Y (0)

/***************************************************
 *　メッセージ表示
 ***************************************************/

/**
 * @brief メッセージ表示 X座標
 */
#define MES_X (50)

/**
 * @brief メッセージ表示 Y座標
 */
#define MES_Y (50)

/**
 * @brief メッセージ表示 幅
 */
#define MES_W (140)

/**
 * @brief メッセージ表示 高さ
 */
#define MES_H (24)

/**
 * @brief ワーニングメッセージ開始まで
 */
#define WAIT_WARNING (3 * 60)


/***************************************************
 *　レベル
 ***************************************************/

/**
 * @brief 最高レベル
 */
#define MAX_LV (8)

/**
 * @brief レベル表示 桁
 */
#define LV_DIGIT (1)

/**
 * @brief レベル表示 X座標
 */
#define LV_X (30)

/**
 * @brief レベル表示 Y座標
 */
#define LV_Y (0)

/**
 * @brief レベルメッセージ X座標
 */
#define LV_MES_X (0)

/**
 * @brief レベルメッセージ Y座標
 */
#define LV_MES_X (0)

/**
 * @brief レベルメッセージ 幅
 */
#define LV_MES_W (28)

/**
 * @brief レベルメッセージ 高さ
 */
#define LV_MES_H (8)

/***************************************************
 *　爆風
 ***************************************************/

/**
 * @brief 爆風 最大値 ブロック
 */
#define FIRE_BOMBS (2)

/**
 * @brief 爆風 繰り返し回数 ブロック
 */
#define REP_BLOCK_BOMBS (2)

/**
 * @brief 爆風 繰り返し回数
 */
#define REP_OVER_BOMBS (3)

/**
 * @brief 爆風 発生範囲
 */
#define BOMB_RANGE (32)

/**
 * @brief 爆風 インターバル
 */
#define BOMB_INTERVAL (5)

/**
 * @brief 爆風 幅
 */
#define BOMB_W (16)

/**
 * @brief 爆風 高さ
 */
#define BOMB_H (16)

/***************************************************
 *　ブラボーメッセージ
 ***************************************************/

/**
 * @brief ブラボー 表示時間
 */
#define BRAVO_LIFE (40)

/**
 * @brief ブラボー Y座標
 */
#define BRAVO_TARGET_Y (-15)

/**
 * @brief ブラボー 幅
 */
#define BRAVO_W (32)

/**
 * @brief ブラボー 高さ
 */
#define BRAVO_H (8)

/**
 * @brief ブラボー Z座標
 */
#define BRAVO_Z (MIN_Z)

/**
 * @brief ブラボー 回復
 */
#define BRAVO_RECOVERY (15)

/***************************************************
 *　BGM
 ***************************************************/

/**
 * @brief ステージBGM数 0-3パターン
 */
#define MAX_STAGE_BGM (3)

///////////////////////////////////////////////////////////////////// ENUM

/**
 * @brief シーン
 */
enum {
    GAME_MAIN = 0,
    GAME_TITLE = 1,
    GAME_PAUSE = 2,
    GAME_OVER = 4,
    GAME_READY = 8,
    GAME_OVER_PRE = 16,
    GAME_CRASH = 32,
    GAME_CLEAR = 64,
    GAME_DEMO = 128,
};

/**
 * @brief スプライトキャラクタ
 */
enum {
    //! 矢印
    SPRITE_ARROW,
    //! ブラボー
    SPRITE_BRAVOICON,
    //! 爆風
    SPRITE_BOMB,
    //! 炎
    SPRITE_FIRE = 4,
    //! 自機
    SPRITE_SHIP,
    //! 逆噴射
    SPRITE_BOOSTER,
    //! 逆噴射アイコン
    SPRITE_BOOSTERICON,
    //! ガイド
    SPRITE_GUIDE,
    //! 境界線
    SPRITE_BOUNDARY_L,
    //! 境界線
    SPRITE_BOUNDARY_R,
    //! リングアイコン
    SPRITE_RINGICON,
    //! ブロック MAX_BLOCKS 分
    SPRITE_BLOCK,
};

/**
 * @brief ブロックの種類
 */
typedef enum {
    //! 通常のブロック
    NORMAL = 0,
    //! ボーナスリング
    RING,
} BlockTypeEnum;

/**
 * @brief 爆風の種類
 */
enum {
    //! ブロック衝突時
    BOMB_BLOCK,
    //! ゲームオーバー時
    BOMB_OVER
};

/**
 * @brief メッセージ点滅モード
 */
enum {
    //! 通常点滅
    MES_BLINK_NORMAL,
    //! 高速点滅
    MES_BLINK_FAST
};

/**
 * @brief トロフィー獲得条件リセット
 */
enum {
    //! すべての条件をリセット
    RESET_TROPHY_ALL,
    //! リングの条件をリセット
    RESET_TROPHY_RING,
    //! ブラボーの条件をリセット
    RESET_TROPHY_BRAVO
};

///////////////////////////////////////////////////////////////////// 構造体

/**
 * @brief 座標 2d
 */
typedef struct
{
    int x;
    int y;
} ALIGN(4) PointType;

/**
 * @brief 矩形
 */
typedef struct
{
    int x;
    int y;
    int w;
    int h;
} ALIGN(4) RectangleType;

/**
 * @brief 座標 3d
 */
typedef struct
{
    int x;
    int y;
    int z;
    //! スケール 1-100%
    int scale;
} ALIGN(4) VectorType;

/**
 * @brief 振動
 */
typedef struct
{
    int range;
    int direc;
    int interval;
    int duration;
} ALIGN(4) ShockType;

/**
 * @brief フラッシュ
 */
typedef struct
{
    u8 color[32];
    int interval;
} ALIGN(4) FlashType;

/**
 * @brief ゲーム管理
 */
typedef struct
{
    int scene;
    int next_scene;
    //! 次のシーンまでのウェイト
    int intermission;
    u16 key;
    u16 keyr;
    int demo_start;
} ALIGN(4) GameStateType;

/**
 * @brief ステージ管理
 */
typedef struct
{
    //! レベル
    int lv;
    //! 次のレベルまで（フレーム数）
    int next_lv;
    //! 獲得リング
    int ring;
    //! 経過フレーム
    int frame;
    //! ステージの中心座標
    VectorType center;
    //! 次のブロックが出現するまでの間隔
    int star_interval;
    //! モード
    int mode;
    //! デモモード
    bool demo;
    //! フラッシュ
    FlashType flash;
    // BGカラー
    u8 bg_color[32];
} ALIGN(4) StageType;

/**
 * @brief フレームアニメ
 */
typedef struct
{
    bool is_start;
    int frame; 
    int max_frame;
    int interval;
    int interval_rel;
} ALIGN(4) AnimeType;

/**
 * @brief スプライト
 */
typedef struct
{
    //! キャラクタ番号 0-127
    int chr;
    //! タイル番号 512-1024
    int tile;
    //! キャラクタータイプ
    BlockTypeEnum type;
    //! 現在の座標
    VectorType vec;
    //! 加速度
    VectorType acc;
    //! 目標の座標
    PointType target;
    //! 座標補正用
    PointType fix;
    //! 中心のオフセット
    PointType center;
    //! 矩形
    RectangleType rect;
    //! 当たり判定用矩形
    RectangleType hit;
    //! 表示フラグ
    bool show;
} ALIGN(4) SpriteCharType;

/**
 * @brief 自機
 */
typedef struct {
    //! エネルギー
    int energy;
    //! 逆噴射
    int booster;
    //! 逆噴射可能か
    bool allows_booster;
    //! 振動
    ShockType shock;
    //! 点滅
    FlashType flash;
    //! スプライト
    SpriteCharType sprite;
} ALIGN(4) ShipType;

/**
 * @brief 炎
 */
typedef struct {
    //! アニメーション用
    AnimeType anime;
    //! スプライト
    SpriteCharType sprite;
} ALIGN(4) FireType;

/**
 * @brief アイコン
 */
typedef struct {
    //! 表示期間
    int life;
    //! 目標座標
    PointType target;
    //! スプライト
    SpriteCharType sprite;
} ALIGN(4) IconType;

/**
 * @brief ブロック管理
 */
typedef struct
{
    //! 出現間隔 Z軸
    int interval;
    //! 出現間隔 Z軸 リロード
    int interval_rel;
    //! 現在の数
    int num;
    //! 最大出現数
    int max_blocks;
    //! 加速度（全てのブロック共通）
    int acc;
    //! デフォルトの速度（全てのブロック共通）
    int speed;
    //! リング出現確率
    int ring_chance;
    //! ブロックのリスト
    SpriteCharType list[MAX_BLOCKS];
} ALIGN(4) BlockType;

/**
 * @brief 爆発管理
 */
typedef struct
{
    //! 現在の数
    int num;
    //! 最大数
    int max;
    //! ベース座標
    PointType base;
    FireType list[FIRE_BOMBS];
} ALIGN(4) BombType;

/**
 * @brief 水平線管理
 */
typedef struct
{
    //! 現在の数
    int num;
    //! 進んだ距離 Z軸
    int z;
    //! 水平線のリスト
    SpriteCharType list[MAX_LINES];
} ALIGN(4) LineType;

/**
 * @brief 境界線
 */
typedef struct {
    //! アニメーション用
    AnimeType anime;
    //! スプライト
    SpriteCharType sprite;
} ALIGN(4) BoundaryType;

/**
 * @brief 点滅メッセージ
 */
typedef struct
{
    bool is_start;
    int x;
    int y;
    int wait;
    int wait_rel;
    int count;
    int chr;
} ALIGN(4) BlinkMessageType;

/**
 * @brief ウェイト
 */
typedef struct
{
    int wait;
} ALIGN(4) WaitType;

/**
 * @brief トロフィー獲得条件
 * 
 */
typedef struct
{
    //! 連続獲得リング
    int continuas_ring;
    //! 連続獲得ブラボー
    int continuas_bravo;
}ALIGN(4) TrophyRequiremnet;

///////////////////////////////////////////////////////////////////// タイル番号

// タイルサイズ
#define TILE_SIZE_8 (2)
#define TILE_SIZE_16 (8)
#define TILE_SIZE_32 (32)
#define TILE_SIZE_64 (128)

// 自機
#define TILE_SHIP1 (512) // 32tiles
#define TILE_SHIP2 (544) // 32
#define TILE_SHIP3 (576) // 32

// 炎
#define TILE_FIRE1 (672) // 8tiles
#define TILE_FIRE2 (680) // 8

// ブロック
#define TILE_BLOCK1 (688) // 128tiles

// リング
#define TILE_RING1 (816) // 128tiles

// ガイド
#define TILE_GUIDE1 (944) // 2tiles

// 境界線
//#define TILE_BOUNDARY1 (946) // 8tiles

// リングアイコン
#define TILE_RINGICON1 (954) // 8tiles

// 逆噴射
#define TILE_BOOSTER1 (962) // 8tiles
#define TILE_BOOSTER2 (970) // 8

// 逆噴射アイコン
#define TILE_BOOSTERICON1 (978) // 2tiles
#define TILE_BOOSTERICON2 (980) // 2

// 爆風
#define TILE_BOMB1 (982) // 8tiles
#define TILE_BOMB2 (990) // 8
#define TILE_BOMB3 (998) // 8
#define TILE_BOMB4 (1006) // 8

// ブラボー
#define TILE_BRAVO1 (1014) // 8tiles

// 矢印
#define TILE_ARROW (1022) // 2tiles

///////////////////////////////////////////////////////////////////// SRAM

/**
 * @brief ハイスコアSRAM保存用
 */
#define SRAM_CHECK (0)

/**
 * @brief ハイスコアSRAM保存用
 */
#define SRAM_HISCORE_NORMAL (4)

/**
 * @brief ハイスコアSRAM保存用
 */
#define SRAM_HISCORE_HARD (8)

/**
 * @brief トロフィーフラグ
 */
#define SRAM_TROPHY_NORMAL (12) // 4*6
#define SRAM_TROPHY_HARD (36) // 4*6

/**
 * @brief 乱数の種
 */
#define SRAM_SEED (100)

/**
 * @brief ゲームモード保存
 */
#define SRAM_MODE (104)

/**
 * @brief SRAM書き込みフラグ
 */
#define SRAM_ON ((u32)0xf0f0f0f0)

///////////////////////////////////////////////////////////////////// COLOR

/**
 * @brief 15bit 透過色
 */
#define COLOR_TRANS RGB5(0, 0, 0)

///////////////////////////////////////////////////////////////////// PALETTE COLOR

/**
 * @brief 透過色
 */
#define PAL_TRANS (0)

///////////////////////////////////////////////////////////////////// timer

#define DEF_TIMER_RELOAD (0)

///////////////////////////////////////////////////////////////////// マクロ

/**
 * @brief ランダム
 */
#define RND(MIN, MAX) ((MIN) + (int)(rand() / (float)RAND_MAX * ((MAX) - (MIN) + 1)))

///////////////////////////////////////////////////////////////////// グローバル変数

/**
 * @brief ゲーム管理
 */
GLOBAL GameStateType game_state;

/**
 * @brief ステージ管理
 */
GLOBAL StageType stage;

/**
 * @brief 自機
 */
GLOBAL ShipType ship;

/**
 * @brief 炎
 */
GLOBAL FireType fire;

/**
 * @brief 逆噴射
 */
GLOBAL FireType booster;

/**
 * @brief ブロック
 */
GLOBAL BlockType blocks;

/**
 * @brief 地平線
 */
GLOBAL LineType lines;

 /**
 * @brief 地平線
 */
GLOBAL BombType bomb;

/**
 * @brief ガイド
 */
GLOBAL SpriteCharType guide;

/**
 * @brief 境界線
 * 
 */
// GLOBAL BoundaryType boundary_r;

/**
 * @brief 境界線
 */
// GLOBAL BoundaryType boundary_l;

/**
 * @brief リングアイコン
 */
GLOBAL IconType ring_icon;

/**
 * @brief 逆噴射アイコンアニメ用
 */
GLOBAL AnimeType booster_icon_anime;

/**
 * @brief 通常のメッセージ表示
 */
GLOBAL BlinkMessageType mes;

/**
 * @brief レベルアップ表示
 */
GLOBAL BlinkMessageType lv_mes;

/**
 *　@brief トロフィーメッセージ表示
 */
GLOBAL BlinkMessageType trophy_mes;

/**
 *　@brief トロフィー獲得条件
 */
GLOBAL TrophyRequiremnet trophy_req;

/**
 * @brief ブラボーアイコン
 */
GLOBAL IconType bravo_icon;

/**
 * @brief スコア
 */
GLOBAL int score;

/**
 * @brief ボーナス
 */
GLOBAL int bonus;

/**
 * @brief トータル
 */
GLOBAL int total;

/**
 * @brief ハイスコア
 */
GLOBAL int hiscore;

/**
 * @brief 乱数の種
 */
GLOBAL u32 seed;

/**
 * @brief 現在のステージBGM
 */
GLOBAL int stage_bgm;

/**
 * @brief トロフィー解除フラグ
 */
GLOBAL bool trophy_unlocked[MAX_TROPHY];

///////////////////////////////////////////////////////////////////// プロトタイプ

void game();
void init_game();
void update_hiscore();
void disp_game_mode();
void load_title();

#endif /* _game_h_ */
