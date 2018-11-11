#include <OGRE/OgreNode.h>
#include <OGRE/OgreMesh.h>
#include <OGRE/OgreLight.h>
#include <OGRE/OgreSceneManager.h>



int main(int argc, char const *argv[])
{
	scnMgr =  new Ogre::OgreSceneManager();

	//set light
	scnMgr->setAmbientLight(ColourValue(0.5, 0.5, 0.5));

	Light* light - scnMgr->createLight("MainLight");
	SceneNode* lightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
	lightNode->attachObject(light);

	lightNode->setPosition(20, 80, 50);

	SceneNode* camNode = scnMgr->getRootSceneNode()->createChildSceneNode();

	//create the camera
	Camera* cam = scnMgr->createCamera("myCam");
	cam->setNearClipDistance(5); // specific to this sample
	cam->setAutoAspectRatio(true);
	camNode->attachObject(cam);
	camNode->setPosition(0, 0, 140);

	//and tell it to render into the main window
	getRenderWindow()->addViewport(cam);


	//load mesh
	Entity* ogreEntity = scnMgr->createEntity("ogrehead.mesh");


	SceneNode* ogreNode = scnMgr->getRootSceneNode()->createChildSceneNode();


    ogreNode->attachObject(ogreEntity);

	return 0;
}