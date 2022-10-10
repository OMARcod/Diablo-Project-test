/*
using System;
using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using UnityEngine.UIElements;

public class PlayerMovement : MonoBehaviour
{

    Rigidbody myRigidbody;

    //float myHorizontalInput;

    bool myPlayerIsGrounded;
    //bool myPlayerCanDash = false;

    LayerMask myGroundMask;
    LayerMask myObstacleMask;


    PlayerManager myPlayerManager;

    [SerializeField] float myMaxPlayerSpeed = 30f;
    [SerializeField] float myPlayerForwardAcceleration = 3f;



    [SerializeField] float myJumpForce = 20f;

    [SerializeField] float myPlayerStartSpeed = 5f;

    [SerializeField] float myCurrentPlayerSpeed = 0.0f;

    [SerializeField] float myPlayerTurnSpeed = 10f;
    [SerializeField] float myPlayerTurnAcceleration = 30f;

    [SerializeField] float mySlowDownDuration = 4;
    [SerializeField] float myPlayerSlowedSpeed = 10f;

    //[SerializeField] bool myHasColided = false;



    [SerializeField] float myPlayerTurnSlowDownMultiplier = 0.8f;

    //[SerializeField] float myBoxAddToAcceleration = 2.0f;
    //[SerializeField] float myBoxAddToMaxSpeed = 10.0f;


    float myCurrentTurnVelocity = 0;
    float mySlowDownTimer = 0;
    private float myTempPlayerSpeed = 0;
    private float myUnslowAcceleration = 0;

    int myEnterCount = 0;

    private Transform myFullColider, myDashColider, myPlayerModel;

    private PlayerParticleManager myParticleManager;
    private AccelrationScript myAccelrationScript;

    private GameObject MyGroundCollider;
    void Start()
    {
        myPlayerManager = GetComponent<PlayerManager>();

        myPlayerIsGrounded = false;
        myRigidbody = GetComponent<Rigidbody>();
        myGroundMask = LayerMask.GetMask("Terrain");
        myObstacleMask = LayerMask.GetMask("Obstacle");

        myCurrentPlayerSpeed = myPlayerStartSpeed;

        myFullColider = transform.Find("ObjectColliderFullSize");
        myDashColider = transform.Find("ObjectColliderDash");
        myPlayerModel = transform.Find("player_player");

        myParticleManager = GetComponent<PlayerParticleManager>();

        MyGroundCollider = GameObject.Find("GroundCollider");
    }


    void Update()
    {

        ParticleSystem();

        DashSystem();

        SpeedSystem();

        UpdateAcceleration();

        TurnSystem();

        HandleRotation();

        // CollisionWithObject();

        JumpSystem();
    }



    void FixedUpdate()
    {
        MoveThePlayer();

        myPlayerIsGrounded = IsPlayerOnTheGround();

    }

    private void MoveThePlayer()
    {
        float myY = myRigidbody.velocity.y;
        myRigidbody.velocity = (transform.forward * myCurrentPlayerSpeed) + (transform.right * myCurrentTurnVelocity);
        myRigidbody.velocity = new Vector3(myRigidbody.velocity.x, myY, myRigidbody.velocity.z);
    }

    void UpdateAcceleration()
    {
        if (mySlowDownTimer > 0)
        {
            mySlowDownTimer -= Time.deltaTime;
            AccelerateThePlayerAgain();
        }
    }

    bool IsPlayerOnTheGround()
    {
        //Debug.DrawRay(transform.position, transform.up * -2.0f, Color.red); //Debug code
        return Physics.Raycast(transform.position, transform.up * -1.0f, 1f, myGroundMask);
    }

    //bool IsThePlayerColidedWithObstacle()
    //{
    //    //Debug.DrawRay(transform.position + new Vector3(0, 0.5f, 0), transform.forward * 2.0f, Color.blue); //Debug code
    //    return Physics.Raycast(transform.position + new Vector3(0, 0.5f, 0), transform.forward, 1f, myObstacleMask);
    //}

    void ParticleSystem()
    {
        if (myPlayerIsGrounded && Input.GetKeyDown(KeyCode.Space))
        {
            myParticleManager.PlayJumpParticle();
        }

        if (myPlayerIsGrounded && myParticleManager.GetMyOldGroundedState() == false)
        {
            myParticleManager.PlayLandParticle();
        }

        bool currentSlideState;
        if (Input.GetKey(KeyCode.S))
        {
            currentSlideState = true;
        }
        else
        {
            currentSlideState = false;
        }

        if (currentSlideState && myParticleManager.GetMyOldSlideState() == false)
        {
            myParticleManager.PlaySlideParticle();
        }

        myParticleManager.SetMyOldSlideState(currentSlideState);
        myParticleManager.SetMyOldGroundedState(myPlayerIsGrounded);
    }

    void JumpSystem()
    {

        if (Input.GetKeyDown(KeyCode.Space))
        {
            if (myPlayerIsGrounded)
            {
                myRigidbody.AddForce(Vector3.up * myJumpForce, ForceMode.Impulse);
            }
        }
    }

    void DashSystem()
    {

        if (Input.GetKeyDown(KeyCode.S))
        {
            if (!myPlayerManager.IsInvulnerable())
            {
                if (myPlayerIsGrounded)
                {
                    myFullColider.gameObject.SetActive(false);
                    myDashColider.gameObject.SetActive(true);
                    myPlayerModel.transform.localScale = new Vector3(1.0f, 0.5f, 1.0f);
                }
            }
        }
        else if (Input.GetKeyUp(KeyCode.S))
        {
            myFullColider.gameObject.SetActive(true);
            myDashColider.gameObject.SetActive(false);
            myPlayerModel.transform.localScale = new Vector3(1.0f, 1f, 1.0f);
        }
    }

    private void TurnSystem()
    {
        if (Input.GetKey(KeyCode.A))//left
        {
            Turn(-1);
        }
        else if (Input.GetKey(KeyCode.D)) //right
        {
            Turn(1);
        }
        else
        {
            Turn(0);
        }
    }

    private void SpeedSystem()
    {
        if (myCurrentPlayerSpeed < myMaxPlayerSpeed)
        {
            myCurrentPlayerSpeed += myPlayerForwardAcceleration * Time.deltaTime; //make the player faster 
        }
        else
        {
            myCurrentPlayerSpeed = myMaxPlayerSpeed;
        }
    }

    private void AccelerateThePlayerAgain()
    {
        myCurrentPlayerSpeed += myUnslowAcceleration * Time.deltaTime;
    }

    private void Turn(int direction)
    {
        if (direction == 0)
        {
            if (myCurrentTurnVelocity == 0)
                return;
            float sign = Mathf.Sign(myCurrentTurnVelocity);

            float tempVelocity = Mathf.Abs(myCurrentTurnVelocity);
            tempVelocity -= myPlayerTurnAcceleration * Time.deltaTime * myPlayerTurnSlowDownMultiplier;
            if (tempVelocity <= 0)
            {
                tempVelocity = 0;
            }
            myCurrentTurnVelocity = sign * tempVelocity;
        }
        else
        {
            myCurrentTurnVelocity += direction * myPlayerTurnAcceleration * Time.deltaTime;
            if (myCurrentTurnVelocity > myPlayerTurnSpeed || myCurrentTurnVelocity < -myPlayerTurnSpeed)
            {
                myCurrentTurnVelocity = Mathf.Sign(myCurrentTurnVelocity) * myPlayerTurnSpeed;
            }
        }
    }

    private void HandleRotation()
    {
        //Vector2 fwd = new Vector2(myCurrentPlayerSpeed, myCurrentTurnVelocity);
        Vector3 fwd = transform.forward * myCurrentPlayerSpeed + transform.right * myCurrentTurnVelocity;
        fwd.Normalize();

        //Vector3 newRotation = new Vector3(0, Mathf.Acos(fwd.x) * Mathf.Rad2Deg * Mathf.Sign(myCurrentTurnVelocity), 0);
        myPlayerModel.LookAt(myPlayerModel.transform.position + fwd);
    }

    private void SlowDownTheSpeed()
    {
        mySlowDownTimer = mySlowDownDuration;
        myTempPlayerSpeed = myCurrentPlayerSpeed;
        myCurrentPlayerSpeed = myPlayerSlowedSpeed;
        myUnslowAcceleration = (myTempPlayerSpeed - myPlayerSlowedSpeed) / mySlowDownDuration;
    }

    //private void CollisionWithObject()
    //{
    //    myHasColided = IsThePlayerColidedWithObstacle();
    //    if (myHasColided)
    //    {
    //        Debug.Log("Damage!");
    //        SlowDownTheSpeed();
    //    }
    //}

    //private void OnTriggerEnter(Collider other)
    //{
    //    myAccelrationScript = other.GetComponent<AccelrationScript>();

    //    if (other.gameObject.CompareTag("AccelrationBox"))
    //    {
    //        myEnterCount++;
    //        if (myEnterCount == 2)
    //        {
    //            myEnterCount = 0;
    //            Debug.Log("WOOOO!");
    //            myAccelrationScript.AccelrateThePlayer(ref myMaxPlayerSpeed, ref myPlayerForwardAcceleration);


    //        }
    //    }
    //}

    public void AccelrateThePlayer(float myBoxAddToMaxSpeed, float myBoxAddToAccelration)
    {
        myMaxPlayerSpeed += myBoxAddToMaxSpeed;
        myPlayerForwardAcceleration += myBoxAddToAccelration;
    }

    private void OnCollisionEnter(Collision collision)
    {
        Collider myCollider = collision.GetContact(0).thisCollider;

        if (collision.gameObject.layer == myObstacleMask)
        {
            Debug.Log("Damage!");
            SlowDownTheSpeed();
        }
    }
}


//void MovementSystem()
//{
//    Vector3 forwardMovment = transform.forward * myForwardSpeed * Time.fixedDeltaTime;
//    Vector3 horizontalMove = transform.right * myHorizontalSpeed * myHorizontalInput * Time.fixedDeltaTime;

//    myRigidbody.MovePosition(myRigidbody.position + forwardMovment + horizontalMove);
//}
*/

/*
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AccelrationScript : MonoBehaviour
{

    [SerializeField] float myBoxAddToMaxSpeed;
    [SerializeField] float myBoxAddToAccelration;

    PlayerMovement playerMovment;
    // Start is called before the first frame update
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {

    }



    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Player"))
        {
            playerMovment = other.GetComponentInParent<PlayerMovement>();
            playerMovment.AccelrateThePlayer(myBoxAddToMaxSpeed,myBoxAddToAccelration);
        }
    }


}

*/