#include "../../include/Commands.hpp"

void Invite::invite(Client* client, const std::vector<std::string> commandParts, Server* srv)
{
    if (commandParts.size() < 3)
        return (client->sendReply(ERR_NEEDMOREPARAMS(client->getNickname(), "INVITE")));

	std::string channelName = commandParts[1];
    std::string targetNick = commandParts[2];
    Channel* channel = srv->getChannel(channelName);

    if (!channel)
	    return (client->sendReply(ERR_NOSUCHCHANNEL(client->getNickname(), channelName)));
    if (channel->getOp() != client->getNickname())
		return (client->sendReply(ERR_CHANOPRIVSNEEDED(client->getNickname(), channelName)));
    if(!channel->isPrivate())
        return (client->sendReply("This channel is not private. Use /MODE to set it as private."));
    Client* targetClient = srv->getClient(commandParts.at(2));
    if (!targetClient) 
        return (client->sendMessage(ERR_NOSUCHNICK(client->getPrefix(), commandParts.at(2))));
    channel->inviteUser(targetNick);
    targetClient->sendMessage("You have been invited to join " + channelName);
    client->sendMessage("You invited " + targetNick + " to " + channelName);
}
