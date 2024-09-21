#include "../../include/Commands.hpp"

void Mode::mode(Client* client, const std::vector<std::string> commandParts, Server* srv)
{
    if (commandParts.size() < 3)
        return client->sendReply(ERR_NEEDMOREPARAMS(client->getNickname(), "MODE"));
    

    std::string channelName = commandParts[1];
    std::string mode = commandParts[2];
    
    Channel* channel = srv->getChannel(channelName);

    if (!channel) 
        return client->sendReply(ERR_NOSUCHCHANNEL(client->getNickname(), channelName));

    if (channel->getOp() != client->getNickname()) 
        return client->sendReply(ERR_CHANOPRIVSNEEDED(client->getNickname(), channelName));

    
    if (mode == "+p") 
    {
            channel->setPrivate(true);
            channel->broadcastMessage("Channel " + channelName + " is now private.");
        
    } 
    else if (mode == "-p") 
    {
            channel->setPrivate(false);
            channel->broadcastMessage("Channel " + channelName + " is now public.");
        
    } 
    else 
    {
        client->sendReply(ERR_UNKNOWNMODE(client->getNickname(), mode));
    }
}