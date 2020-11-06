#include "ofApp.h"

const float radius = 30.0f; //�~�̔��a30���`
const vec2 velocity{ 300.0f,200.0f };
//--------------------------------------------------------------
void ofApp::setup(){
	position = vec2{ radius };
	velocity = vec2{ 300.0f,100.0f }; // velocity�ɏ����l��^����
}

//--------------------------------------------------------------
void ofApp::update(){
	// ���O�̃t���[���̎��ԊԊu��ۑ����Ă���
	const float dt = ofGetLastFrameTime();

	// ���݂̉~�̈ʒu���L�^���Ă���
	const vec2 p = position;

	// �~�̈ʒu���X�V����
	position += velocity * dt;

	/*�E���̕ǂŒ��˕Ԃ�悤�ɂ���*/
	// w-r���v�Z����
	const float wr = ofGetWidth() - 1.0f - radius;

	// �����~���E�B���h�E����͂ݏo����
	if (position.x >= wr)
	{
		// �ǂƏՓ˂������������߂�
		const float t = (wr - p.x) / velocity.x;

		// �Փ˂����ʒu�����߂�
		const vec2  q = vec2{ wr, p.y + velocity.y * t };

		// �Փˌ�̑��x��ύX����
		velocity = vec2{ -velocity.x, velocity.y };

		// �~�̈ʒu��ύX����
		position = q + velocity * (dt - t);
	}

	/*���̕ǂŒ��˕Ԃ�悤�ɂ���*/
	// h-r���v�Z����
	const float hr = ofGetHeight() - 1.0f - radius;

	// �����~���E�B���h�E����͂ݏo����
	if (position.y >= hr)
	{
		// �ǂƏՓ˂������������߂�
		const float t = (hr - p.y) / velocity.y;

		// �Փ˂����ʒu�����߂�
		const vec2  q = vec2{ p.x + velocity.x * t, hr };

		// �Փˌ�̑��x��ύX����
		velocity = vec2{ velocity.x, -velocity.y };

		// �~�̈ʒu��ύX����
		position = q + velocity * (dt - t);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofDrawCircle(0.0f, 0.0f, 30.0f); //���S(0,0)�Ŕ��a30�̉~��`��

	ofDrawCircle(position, radius); //�~��`��
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
