#include "ofApp.h"

const float radius = 30.0f; //円の半径30を定義
const vec2 velocity{ 300.0f,200.0f };
//--------------------------------------------------------------
void ofApp::setup(){
	position = vec2{ radius };
	velocity = vec2{ 300.0f,100.0f }; // velocityに初期値を与える
}

//--------------------------------------------------------------
void ofApp::update(){
	// 直前のフレームの時間間隔を保存しておく
	const float dt = ofGetLastFrameTime();

	// 現在の円の位置を記録しておく
	const vec2 p = position;

	// 円の位置を更新する
	position += velocity * dt;

	/*右側の壁で跳ね返るようにする*/
	// w-rを計算する
	const float wr = ofGetWidth() - 1.0f - radius;

	// もし円がウィンドウからはみ出たら
	if (position.x >= wr)
	{
		// 壁と衝突した時刻を求める
		const float t = (wr - p.x) / velocity.x;

		// 衝突した位置を求める
		const vec2  q = vec2{ wr, p.y + velocity.y * t };

		// 衝突後の速度を変更する
		velocity = vec2{ -velocity.x, velocity.y };

		// 円の位置を変更する
		position = q + velocity * (dt - t);
	}

	/*下の壁で跳ね返るようにする*/
	// h-rを計算する
	const float hr = ofGetHeight() - 1.0f - radius;

	// もし円がウィンドウからはみ出たら
	if (position.y >= hr)
	{
		// 壁と衝突した時刻を求める
		const float t = (hr - p.y) / velocity.y;

		// 衝突した位置を求める
		const vec2  q = vec2{ p.x + velocity.x * t, hr };

		// 衝突後の速度を変更する
		velocity = vec2{ velocity.x, -velocity.y };

		// 円の位置を変更する
		position = q + velocity * (dt - t);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofDrawCircle(0.0f, 0.0f, 30.0f); //中心(0,0)で半径30の円を描く

	ofDrawCircle(position, radius); //円を描く
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
