use tonic::{transport::Server, Request, Response, Status};
use voting::{VotingRequest, VotingResponse, voting_server::{Voting, VotingServer}};

pub mod voting {
    tonic::include_proto!("voting");
}

#[derive(Debug, Default)]
pub struct VotingService {}

#[tonic::async_trait]
impl Voting for VotingService {
    async fn vote(&self, request: Request<VotingRequest>) -> Result<Response<VotingResponse>, Status> {
        let r = request.into_inner();
        match r.vote {
            0 => Ok(Response::new(voting::VotingResponse {confirmation: {
                format!("Upvoted for {}", r.url)
            }})),
            1 => Ok(Response::new(voting::VotingResponse {confirmation: {
                format!("Downvoted for {}", r.url)
            }})),
            _ => Err(Status::new(tonic::Code::OutOfRange, "Invalid vote provided"))
        }
    }
}

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    let address = "[::1]:8080".parse().unwrap();
    let voting_service = VotingService::default();

    Server::builder().add_service(VotingServer::new(voting_service))
        .serve(address).await?;
    Ok(())
}
